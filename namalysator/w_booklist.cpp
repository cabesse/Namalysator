#include "w_booklist.h"
#include <QModelIndex>

w_booklist::w_booklist(dbrequest & _db,QWidget *parent):db(_db),QWidget(parent){
	//init();
}

w_booklist::~w_booklist(){
}

void w_booklist::init(bool sampling){
	_mainLayout = new QVBoxLayout();
	this->setLayout(_mainLayout);
	bookView= new QTableView();
	_mainLayout->addWidget ( bookView );

	_bookModel = new bookModel(db);
	_bookModel->init(sampling);
	proxyModel = new QSortFilterProxyModel();
	proxyModel->setSourceModel(_bookModel);

	bookView->setModel(proxyModel);
	bookView->verticalHeader()->hide();
	bookView->setEditTriggers(QAbstractItemView::NoEditTriggers);  
    bookView->setSelectionMode(QAbstractItemView::SingleSelection);  
    bookView->setSelectionBehavior(QAbstractItemView::SelectRows);  
	bookView->setAlternatingRowColors(true);
	bookView->setShowGrid(false);
  	bookView->setHorizontalHeader(new bookColumn(Qt::Horizontal));
	bookView->setSortingEnabled(true);
	bookView->resizeColumnsToContents();
	bookView->resizeRowsToContents();

	connect ( bookView, SIGNAL(clicked(QModelIndex)), this, SLOT(onclick(QModelIndex)));
}

void w_booklist::samplingSelection(){
	_bookModel->init(true);
}
void w_booklist::allSelection(){
	_bookModel->init(false);
}


void w_booklist::onclick(const QModelIndex & idx){
	int metsId = _bookModel->idMets(proxyModel->mapToSource(idx));
	if ( idx.column()  != 3 ) {
		emit metsIdSelected( metsId );
	} else {
		emit metsThumb( metsId );
		//emit metsIdSelected( metsId );
	}
}