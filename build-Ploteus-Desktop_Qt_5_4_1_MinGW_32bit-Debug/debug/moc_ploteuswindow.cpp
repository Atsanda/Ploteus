/****************************************************************************
** Meta object code from reading C++ file 'ploteuswindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Ploteus/ploteuswindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ploteuswindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PloteusWindow_t {
    QByteArrayData data[5];
    char stringdata[76];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PloteusWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PloteusWindow_t qt_meta_stringdata_PloteusWindow = {
    {
QT_MOC_LITERAL(0, 0, 13), // "PloteusWindow"
QT_MOC_LITERAL(1, 14, 27), // "turn_strtpage_to_tbl_chs_pg"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 19), // "load_external_table"
QT_MOC_LITERAL(4, 63, 12) // "create_table"

    },
    "PloteusWindow\0turn_strtpage_to_tbl_chs_pg\0"
    "\0load_external_table\0create_table"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PloteusWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x0a /* Public */,
       3,    0,   30,    2, 0x0a /* Public */,
       4,    0,   31,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PloteusWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PloteusWindow *_t = static_cast<PloteusWindow *>(_o);
        switch (_id) {
        case 0: _t->turn_strtpage_to_tbl_chs_pg(); break;
        case 1: _t->load_external_table(); break;
        case 2: _t->create_table(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject PloteusWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_PloteusWindow.data,
      qt_meta_data_PloteusWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PloteusWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PloteusWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PloteusWindow.stringdata))
        return static_cast<void*>(const_cast< PloteusWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int PloteusWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
