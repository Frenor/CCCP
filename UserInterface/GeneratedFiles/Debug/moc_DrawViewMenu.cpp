/****************************************************************************
** Meta object code from reading C++ file 'DrawViewMenu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DrawViewMenu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DrawViewMenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DrawViewMenu_t {
    QByteArrayData data[10];
    char stringdata[116];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DrawViewMenu_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DrawViewMenu_t qt_meta_stringdata_DrawViewMenu = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 9),
QT_MOC_LITERAL(2, 23, 0),
QT_MOC_LITERAL(3, 24, 9),
QT_MOC_LITERAL(4, 34, 18),
QT_MOC_LITERAL(5, 53, 7),
QT_MOC_LITERAL(6, 61, 18),
QT_MOC_LITERAL(7, 80, 15),
QT_MOC_LITERAL(8, 96, 3),
QT_MOC_LITERAL(9, 100, 15)
    },
    "DrawViewMenu\0newAction\0\0operation\0"
    "propertiesSelected\0Entity*\0"
    "dimensionsSelected\0showContextMenu\0"
    "pos\0drawTypeChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DrawViewMenu[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    1,   42,    2, 0x06 /* Public */,
       6,    1,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   48,    2, 0x0a /* Public */,
       9,    1,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 5,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QPoint,    8,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void DrawViewMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DrawViewMenu *_t = static_cast<DrawViewMenu *>(_o);
        switch (_id) {
        case 0: _t->newAction((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->propertiesSelected((*reinterpret_cast< Entity*(*)>(_a[1]))); break;
        case 2: _t->dimensionsSelected((*reinterpret_cast< Entity*(*)>(_a[1]))); break;
        case 3: _t->showContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 4: _t->drawTypeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
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
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Entity* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DrawViewMenu::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DrawViewMenu::newAction)) {
                *result = 0;
            }
        }
        {
            typedef void (DrawViewMenu::*_t)(Entity * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DrawViewMenu::propertiesSelected)) {
                *result = 1;
            }
        }
        {
            typedef void (DrawViewMenu::*_t)(Entity * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DrawViewMenu::dimensionsSelected)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject DrawViewMenu::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DrawViewMenu.data,
      qt_meta_data_DrawViewMenu,  qt_static_metacall, 0, 0}
};


const QMetaObject *DrawViewMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DrawViewMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DrawViewMenu.stringdata))
        return static_cast<void*>(const_cast< DrawViewMenu*>(this));
    return QObject::qt_metacast(_clname);
}

int DrawViewMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void DrawViewMenu::newAction(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DrawViewMenu::propertiesSelected(Entity * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DrawViewMenu::dimensionsSelected(Entity * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
