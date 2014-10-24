/****************************************************************************
** Meta object code from reading C++ file 'DrawController.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DrawController.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DrawController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DrawController_t {
    QByteArrayData data[13];
    char stringdata[156];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DrawController_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DrawController_t qt_meta_stringdata_DrawController = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 15),
QT_MOC_LITERAL(2, 31, 0),
QT_MOC_LITERAL(3, 32, 7),
QT_MOC_LITERAL(4, 40, 5),
QT_MOC_LITERAL(5, 46, 8),
QT_MOC_LITERAL(6, 55, 10),
QT_MOC_LITERAL(7, 66, 9),
QT_MOC_LITERAL(8, 76, 9),
QT_MOC_LITERAL(9, 86, 11),
QT_MOC_LITERAL(10, 98, 12),
QT_MOC_LITERAL(11, 111, 25),
QT_MOC_LITERAL(12, 137, 18)
    },
    "DrawController\0setActiveEntity\0\0Entity*\0"
    "reset\0setModel\0DrawModel*\0DrawModel\0"
    "doneEvent\0cancelEvent\0actorClicked\0"
    "vtkSmartPointer<vtkActor>\0actorDoubleClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DrawController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x0a /* Public */,
       4,    0,   52,    2, 0x0a /* Public */,
       5,    1,   53,    2, 0x0a /* Public */,
       8,    0,   56,    2, 0x0a /* Public */,
       9,    0,   57,    2, 0x0a /* Public */,
      10,    1,   58,    2, 0x0a /* Public */,
      12,    1,   61,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,    2,
    QMetaType::Void, 0x80000000 | 11,    2,

       0        // eod
};

void DrawController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DrawController *_t = static_cast<DrawController *>(_o);
        switch (_id) {
        case 0: _t->setActiveEntity((*reinterpret_cast< Entity*(*)>(_a[1]))); break;
        case 1: _t->reset(); break;
        case 2: _t->setModel((*reinterpret_cast< DrawModel*(*)>(_a[1]))); break;
        case 3: _t->doneEvent(); break;
        case 4: _t->cancelEvent(); break;
        case 5: _t->actorClicked((*reinterpret_cast< vtkSmartPointer<vtkActor>(*)>(_a[1]))); break;
        case 6: _t->actorDoubleClicked((*reinterpret_cast< vtkSmartPointer<vtkActor>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Entity* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< DrawModel* >(); break;
            }
            break;
        }
    }
}

const QMetaObject DrawController::staticMetaObject = {
    { &GraphicController::staticMetaObject, qt_meta_stringdata_DrawController.data,
      qt_meta_data_DrawController,  qt_static_metacall, 0, 0}
};


const QMetaObject *DrawController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DrawController::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DrawController.stringdata))
        return static_cast<void*>(const_cast< DrawController*>(this));
    return GraphicController::qt_metacast(_clname);
}

int DrawController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GraphicController::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
