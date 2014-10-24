/****************************************************************************
** Meta object code from reading C++ file 'LeftWidgetResult.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../LeftWidgetResult.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LeftWidgetResult.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_LeftWidgetResult_t {
    QByteArrayData data[7];
    char stringdata[76];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LeftWidgetResult_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LeftWidgetResult_t qt_meta_stringdata_LeftWidgetResult = {
    {
QT_MOC_LITERAL(0, 0, 16),
QT_MOC_LITERAL(1, 17, 8),
QT_MOC_LITERAL(2, 26, 0),
QT_MOC_LITERAL(3, 27, 12),
QT_MOC_LITERAL(4, 40, 7),
QT_MOC_LITERAL(5, 48, 16),
QT_MOC_LITERAL(6, 65, 10)
    },
    "LeftWidgetResult\0setModel\0\0ResultModel*\0"
    "clicked\0QListWidgetItem*\0updateList"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LeftWidgetResult[] = {

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
       1,    1,   29,    2, 0x0a /* Public */,
       4,    1,   32,    2, 0x0a /* Public */,
       6,    0,   35,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void,

       0        // eod
};

void LeftWidgetResult::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LeftWidgetResult *_t = static_cast<LeftWidgetResult *>(_o);
        switch (_id) {
        case 0: _t->setModel((*reinterpret_cast< ResultModel*(*)>(_a[1]))); break;
        case 1: _t->clicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->updateList(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ResultModel* >(); break;
            }
            break;
        }
    }
}

const QMetaObject LeftWidgetResult::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_LeftWidgetResult.data,
      qt_meta_data_LeftWidgetResult,  qt_static_metacall, 0, 0}
};


const QMetaObject *LeftWidgetResult::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LeftWidgetResult::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LeftWidgetResult.stringdata))
        return static_cast<void*>(const_cast< LeftWidgetResult*>(this));
    return QWidget::qt_metacast(_clname);
}

int LeftWidgetResult::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
