#ifndef _BOOKMODEL_H
#define _BOOKMODEL_H

#include <QAbstractTableModel>
#include "dbrequest.h"
//** implement model of book to be able to developp : use by the tableview widget

class bookModel : public QAbstractTableModel {
public:
	bookModel(dbrequest & _db,QObject *parent = 0);
	virtual ~bookModel();

    virtual QModelIndex parent(const QModelIndex &child) const ;
	virtual int rowCount(const QModelIndex &parent = QModelIndex()) const ;
    virtual int columnCount(const QModelIndex &parent = QModelIndex()) const ;
	virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const ;
	virtual QVariant headerData ( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const;


	virtual void init(bool sampling);

	int idMets ( const QModelIndex &index );

protected:
	dbrequest& db;
	std::vector<std::vector<QVariant> > allMets;
};

class bookModelE : public bookModel {
	    Q_OBJECT
public:
	bookModelE(dbrequest & _db,QObject *parent = 0);
	virtual ~bookModelE();

	virtual Qt::ItemFlags flags(const QModelIndex &index) const;
	virtual bool bookModelE::setData(const QModelIndex &index, const QVariant &value, int /* role */);
signals:
	void changeProgressWarn(const QModelIndex &index, int value);
};


class bookModelInventory : public bookModel {
public:
	bookModelInventory(dbrequest & _db,QObject *parent = 0):bookModel(_db,parent){};
	virtual ~bookModelInventory(){};

	virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const ;
	virtual QVariant headerData ( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const;

	virtual void init();
};


#endif