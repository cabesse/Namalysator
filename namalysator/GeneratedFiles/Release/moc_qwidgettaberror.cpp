/****************************************************************************
** Meta object code from reading C++ file 'qwidgettaberror.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qwidgettaberror.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwidgettaberror.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_tabErrors[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   11,   10,   10, 0x08,
      49,   40,   10,   10, 0x08,
      77,   72,   10,   10, 0x08,
     104,   96,   10,   10, 0x08,
     125,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_tabErrors[] = {
    "tabErrors\0\0,\0accepted(bool,std::string)\0"
    "category\0getcbCategory(QString)\0year\0"
    "getcbYear(QString)\0col,row\0"
    "lineChanged(int,int)\0findNext()\0"
};

void tabErrors::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        tabErrors *_t = static_cast<tabErrors *>(_o);
        switch (_id) {
        case 0: _t->accepted((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2]))); break;
        case 1: _t->getcbCategory((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->getcbYear((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->lineChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->findNext(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData tabErrors::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject tabErrors::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_tabErrors,
      qt_meta_data_tabErrors, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &tabErrors::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *tabErrors::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *tabErrors::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_tabErrors))
        return static_cast<void*>(const_cast< tabErrors*>(this));
    return QWidget::qt_metacast(_clname);
}

int tabErrors::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
