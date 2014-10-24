/****************************************************************************
** Meta object code from reading C++ file 'ResultController.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ResultController.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ResultController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ResultController_t {
    QByteArrayData data[6];
    char stringdata[70];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ResultController_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ResultController_t qt_meta_stringdata_ResultController = {
    {
QT_MOC_LITERAL(0, 0, 16),
QT_MOC_LITERAL(1, 17, 5),
QT_MOC_LITERAL(2, 23, 0),
QT_MOC_LITERAL(3, 24, 10),
QT_MOC_LITERAL(4, 35, 20),
QT_MOC_LITERAL(5, 56, 13)
    },
    "ResultController\0reset\0\0invalidate\0"
    "createScalarBarActor\0setVisibility"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ResultController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x0a /* Public */,
       3,    0,   35,    2, 0x0a /* Public */,
       4,    0,   36,    2, 0x0a /* Public */,
       5,    0,   37,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ResultController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ResultController *_t = static_cast<ResultController *>(_o);
        switch (_id) {
        case 0: _t->reset(); break;
        case 1: _t->invalidate(); break;
        case 2: _t->createScalarBarActor(); break;
        case 3: _t->setVisibility(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject ResultController::staticMetaObject = {
    { &GraphicController::staticMetaObject, qt_meta_stringdata_ResultController.data,
      qt_meta_data_ResultController,  qt_static_metacall, 0, 0}
};


const QMetaObject *ResultController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ResultController::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ResultController.stringdata))
        return static_cast<void*>(const_cast< ResultController*>(this));
    return GraphicController::qt_metacast(_clname);
}

int ResultController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GraphicController::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
