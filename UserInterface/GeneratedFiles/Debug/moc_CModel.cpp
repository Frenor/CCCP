/****************************************************************************
** Meta object code from reading C++ file 'CModel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CModel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CModel_t {
    QByteArrayData data[19];
    char stringdata[258];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CModel_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CModel_t qt_meta_stringdata_CModel = {
    {
QT_MOC_LITERAL(0, 0, 6),
QT_MOC_LITERAL(1, 7, 12),
QT_MOC_LITERAL(2, 20, 0),
QT_MOC_LITERAL(3, 21, 10),
QT_MOC_LITERAL(4, 32, 8),
QT_MOC_LITERAL(5, 41, 8),
QT_MOC_LITERAL(6, 50, 10),
QT_MOC_LITERAL(7, 61, 13),
QT_MOC_LITERAL(8, 75, 21),
QT_MOC_LITERAL(9, 97, 16),
QT_MOC_LITERAL(10, 114, 18),
QT_MOC_LITERAL(11, 133, 18),
QT_MOC_LITERAL(12, 152, 19),
QT_MOC_LITERAL(13, 172, 21),
QT_MOC_LITERAL(14, 194, 8),
QT_MOC_LITERAL(15, 203, 13),
QT_MOC_LITERAL(16, 217, 11),
QT_MOC_LITERAL(17, 229, 11),
QT_MOC_LITERAL(18, 241, 16)
    },
    "CModel\0newDrawModel\0\0DrawModel*\0"
    "drawMode\0meshMode\0resultMode\0uiModeChanged\0"
    "setDataModelListeners\0setMeshOutOfSync\0"
    "setResultOutOfSync\0executeMeshProcess\0"
    "executeSolveProcess\0moveToTemporaryFolder\0"
    "filename\0tmpFileEnding\0openMSHFile\0"
    "openVTKFile\0resetMeshOptions"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,
       4,    0,   87,    2, 0x06 /* Public */,
       5,    0,   88,    2, 0x06 /* Public */,
       6,    0,   89,    2, 0x06 /* Public */,
       7,    0,   90,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   91,    2, 0x0a /* Public */,
       9,    0,   92,    2, 0x0a /* Public */,
      10,    0,   93,    2, 0x0a /* Public */,
      11,    0,   94,    2, 0x0a /* Public */,
      12,    0,   95,    2, 0x0a /* Public */,
      13,    2,   96,    2, 0x0a /* Public */,
      16,    1,  101,    2, 0x0a /* Public */,
      17,    1,  104,    2, 0x0a /* Public */,
      18,    0,  107,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   14,   15,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,

       0        // eod
};

void CModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CModel *_t = static_cast<CModel *>(_o);
        switch (_id) {
        case 0: _t->newDrawModel((*reinterpret_cast< DrawModel*(*)>(_a[1]))); break;
        case 1: _t->drawMode(); break;
        case 2: _t->meshMode(); break;
        case 3: _t->resultMode(); break;
        case 4: _t->uiModeChanged(); break;
        case 5: _t->setDataModelListeners(); break;
        case 6: _t->setMeshOutOfSync(); break;
        case 7: _t->setResultOutOfSync(); break;
        case 8: _t->executeMeshProcess(); break;
        case 9: _t->executeSolveProcess(); break;
        case 10: _t->moveToTemporaryFolder((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 11: _t->openMSHFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->openVTKFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->resetMeshOptions(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< DrawModel* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CModel::*_t)(DrawModel * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CModel::newDrawModel)) {
                *result = 0;
            }
        }
        {
            typedef void (CModel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CModel::drawMode)) {
                *result = 1;
            }
        }
        {
            typedef void (CModel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CModel::meshMode)) {
                *result = 2;
            }
        }
        {
            typedef void (CModel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CModel::resultMode)) {
                *result = 3;
            }
        }
        {
            typedef void (CModel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CModel::uiModeChanged)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject CModel::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CModel.data,
      qt_meta_data_CModel,  qt_static_metacall, 0, 0}
};


const QMetaObject *CModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CModel.stringdata))
        return static_cast<void*>(const_cast< CModel*>(this));
    return QObject::qt_metacast(_clname);
}

int CModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void CModel::newDrawModel(DrawModel * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CModel::drawMode()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void CModel::meshMode()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void CModel::resultMode()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void CModel::uiModeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}
QT_END_MOC_NAMESPACE
