#include "transform.h"

#include <iostream>
#include <map>
#include <string>


#define CTX ((transformContext*)ctx)

class FptrElem : public StateTransformRootState{

private :

	char* type;


public :

	virtual void endElement (const char* const name);
	

};

void FptrElem::endElement (const char* const name){

	CTX->fileStream  << "<fptr><area/></fptr>" << std::endl;

}


class DivElem : public StateTransformRootState{

private :

	StateParserState* clean1;
	StateParserState* clean2;

	std::string type;

public :

	DivElem():clean1(0),clean2(0){};

		//virtual void characters (const char* const chars, const int len);
    virtual void startElement (const char* const name, const xercesc::Attributes &attrs );
	virtual void endElement (const char* const name);
	virtual StateParserState* getNext(const char* const name);
	

};

void DivElem::startElement (const char* const name, const xercesc::Attributes &attrs ){
	char* tmp = getAttributeValue ("TYPE" , attrs);

	if ( tmp != 0 ){
		type = tmp;
	}else{
		std::cerr << "Problem: tag div without TYPE" << std::endl;
		type = "";
	};

	if ( CTX->firstTag ) {
		CTX->fileStream << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << std::endl;
		CTX->fileStream << "<" << type << " xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns=\"http://BNL.Namespace/\" xsi:schemaLocation=\"http://BNL.Namespace/ bnl-monograph_v1.0.xsd\" >" << std::endl;
		CTX->firstTag = false;
	}else{
		CTX->fileStream << "<" << type << ">" << std::endl;
	}

}

void DivElem::endElement (const char* const name){
	
	CTX->fileStream << "</" << type << ">"<< std::endl ;
	
	if ( clean1 ) {delete clean1; clean1  = 0;} 
	if ( clean2 ) {delete clean2; clean2  = 0;} 
}

StateParserState* DivElem::getNext(const char* const name){
	std::map<std::string,StateParserState*> map;
	static StateParserState* root=new StateTransformRootState();

	StateParserState* ret=root;

	map["div"]=	clean1 = new DivElem();
	map["fptr"]= clean2 = new FptrElem();

	std::map<std::string,StateParserState*>::iterator it = map.find(name);
	if ( it != map.end()) ret = (*it).second;

	return ret;
}






class StructMapElem : public StateTransformRootState{

private : 
	bool flagLogical;

public :

		//virtual void characters (const char* const chars, const int len);
    virtual void startElement (const char* const name, const xercesc::Attributes &attrs );
	virtual void endElement (const char* const name);
	virtual StateParserState* getNext(const char* const name);

};

void StructMapElem::startElement(const char *const name, const xercesc_3_1::Attributes &attrs){
	char* type = getAttributeValue ("TYPE" , attrs);

	if ( type && strcmp ( type , "LOGICAL" )==0 ) {
		flagLogical = true;
	}else {
		flagLogical = false;
	}

}

void StructMapElem::endElement(const char *const name){
	//std::cerr << "name:" << name << std::endl;
	flagLogical = false;
}

StateParserState* StructMapElem::getNext(const char* const name){
	static std::map<std::string,StateParserState*> map;
	static StateParserState* root=new StateTransformRootState();

	if ( flagLogical==false ) { return StateTransformRootState::getNext(name); };


	StateParserState* ret=root;
	
	static struct _onlyOnes {
		_onlyOnes(std::map<std::string,StateParserState*>& map){
			map["div"]=	new DivElem();
			map["fptr"]= new FptrElem();// sub state machine
		}
	} onlyOnes (map);

	std::map<std::string,StateParserState*>::iterator it = map.find(name);
	if ( it != map.end()) ret = (*it).second;

	return ret;
}


StateParserState* StateTransformRootState::getNext(const char* const name){
	static std::map<std::string,StateParserState*> map;
	static StateParserState* root=new StateTransformRootState();

	StateParserState* ret=root;
	
	static struct _onlyOnes {
		_onlyOnes(std::map<std::string,StateParserState*>& map){
			map["structMap"]=	new StructMapElem(); // sub state machine
		}
	} onlyOnes (map);

	std::map<std::string,StateParserState*>::iterator it = map.find(name);
	if ( it != map.end()) ret = (*it).second;

	return ret;
}

transformParser::transformParser():StateParserCH(ctx,_root){
}


void transformContext::openFile ( std::string _filename ){
	filename = _filename;

	fileStream.open(filename.c_str(), std::ios::out | std::ios::trunc);

	if ( fileStream.is_open() ) return;

	std::cerr << "Unable to open file" << filename << std::endl;
	// TODO Nice to throw exception

}
void transformContext::closeFile (){
	fileStream.close();
}
