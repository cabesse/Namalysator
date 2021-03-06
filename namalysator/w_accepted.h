#ifndef ACCEPETED_H
#define ACCEPETED_H

#include <qcheckbox.h>
#include <string>
#include "dbrequest.h"

class acceptedW : public QCheckBox {
	    Q_OBJECT;
public :
	acceptedW( int _value,std::string _hash,QWidget * parent = 0);
public slots:
	void change(bool);

signals:
	void changeHash(bool,std::string);

private :
	int value;
	std::string hashkey;
};

#endif