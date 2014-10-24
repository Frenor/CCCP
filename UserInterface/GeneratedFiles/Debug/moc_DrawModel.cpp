/****************************************************************************
** Meta object code from reading C++ file 'DrawModel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DrawModel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DrawModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DrawModel_t {
    QByteArrayData data[15];
    char stringdata[219];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DrawModel_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DrawModel_t qt_meta_stringdata_DrawModel = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 13),
QT_MOC_LITERAL(2, 24, 0),
QT_MOC_LITERAL(3, 25, 7),
QT_MOC_LITERAL(4, 33, 13),
QT_MOC_LITERAL(5, 47, 13),
QT_MOC_LITERAL(6, 61, 19),
QT_MOC_LITERAL(7, 81, 13),
QT_MOC_LITERAL(8, 95, 16),
QT_MOC_LITERAL(9, 112, 20),
QT_MOC_LITERAL(10, 133, 19),
QT_MOC_LITERAL(11, 153, 22),
QT_MOC_LITERAL(12, 176, 16),
QT_MOC_LITERAL(13, 193, 10),
QT_MOC_LITERAL(14, 204, 14)
    },
    "DrawModel\0entityCreated\0\0Entity*\0"
    "entityChanged\0entityDeleted\0"
    "activeEntityChanged\0uiModeChanged\0"
    "setEntityChanged\0finalizeActiveEntity\0"
    "setActiveEntityNULL\0executeEntityOperation\0"
    "EntityOperation*\0eOperation\0showProperties"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DrawModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    1,   67,    2, 0x06 /* Public */,
       5,    1,   70,    2, 0x06 /* Public */,
       6,    1,   73,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   76,    2, 0x0a /* Public */,
       8,    1,   77,    2, 0x0a /* Public */,
       9,    0,   80,    2, 0x0a /* Public */,
      10,    0,   81,    2, 0x0a /* Public */,
      11,    1,   82,    2, 0x0a /* Public */,
      14,    1,   85,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, 0x80000000 | 3,    2,

       0        // eod
};

void DrawModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DrawModel *_t = static_cast<DrawModel *>(_o);
        switch (_id) {
        case 0: _t->entityCreated((*reinterpret_cast< Entity*(*)>(_a[1]))); break;
        case 1: _t->entityChanged((*reinterpret_cast< Entity*(*)>(_a[1]))); break;
        case 2: _t->entityDeleted((*reinterpret_cast< Entity*(*)>(_a[1]))); break;
        case 3: _t->activeEntityChanged((*reinterpret_cast< Entity*(*)>(_a[1]))); break;
        case 4: _t->uiModeChanged(); break;
        case 5: _t->setEntityChanged((*reinterpret_cast< Entity*(*)>(_a[1]))); break;
        case 6: _t->finalizeActiveEntity(); break;
        case 7: _t->setActiveEntityNULL(); break;
        case 8: _t->executeEntityOperation((*reinterpret_cast< EntityOperation*(*)>(_a[1]))); break;
        case 9: _t->showProperties((*reinterpret_cast< Entity*(*)>(_a[1]))); break;
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
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Entity* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Entity* >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< EntityOperation* >(); break;
            }
            break;
        case 9:
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
            typedef void (DrawModel::*_t)(Entity * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DrawModel::entityCreated)) {
                *result = 0;
            }
        }
        {
            typedef void (DrawModel::*_t)(Entity * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DrawModel::entityChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (DrawModel::*_t)(Entity * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DrawModel::entityDeleted)) {
                *result = 2;
            }
        }
        {
            typedef void (DrawModel::*_t)(Entity * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DrawModel::activeEntityChanged)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject DrawModel::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DrawModel.data,
      qt_meta_data_DrawModel,  qt_static_metacall, 0, 0}
};


const QMetaObject *DrawModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DrawModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DrawModel.stringdata))
        return static_cast<void*>(const_cast< DrawModel*>(this));
    return QObject::qt_metacast(_clname);
}

int DrawModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void DrawModel::entityCreated(Entity * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DrawModel::entityChanged(Entity * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DrawModel::entityDeleted(Entity * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void DrawModel::activeEntityChanged(Entity * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
