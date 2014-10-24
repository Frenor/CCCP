/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[23];
    char stringdata[301];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 11),
QT_MOC_LITERAL(2, 23, 0),
QT_MOC_LITERAL(3, 24, 13),
QT_MOC_LITERAL(4, 38, 10),
QT_MOC_LITERAL(5, 49, 9),
QT_MOC_LITERAL(6, 59, 12),
QT_MOC_LITERAL(7, 72, 8),
QT_MOC_LITERAL(8, 81, 8),
QT_MOC_LITERAL(9, 90, 7),
QT_MOC_LITERAL(10, 98, 7),
QT_MOC_LITERAL(11, 106, 11),
QT_MOC_LITERAL(12, 118, 11),
QT_MOC_LITERAL(13, 130, 13),
QT_MOC_LITERAL(14, 144, 18),
QT_MOC_LITERAL(15, 163, 12),
QT_MOC_LITERAL(16, 176, 20),
QT_MOC_LITERAL(17, 197, 17),
QT_MOC_LITERAL(18, 215, 17),
QT_MOC_LITERAL(19, 233, 18),
QT_MOC_LITERAL(20, 252, 16),
QT_MOC_LITERAL(21, 269, 14),
QT_MOC_LITERAL(22, 284, 16)
    },
    "MainWindow\0meshVisible\0\0resultVisible\0"
    "addPolygon\0addCircle\0deleteEntity\0"
    "openFile\0saveFile\0newFile\0setMode\0"
    "setDrawMode\0setMeshMode\0setResultMode\0"
    "showDrawController\0showMeshView\0"
    "showResultController\0setMinElementSize\0"
    "setMaxElementSize\0setCustomArguments\0"
    "resetMeshOptions\0setMeshVisible\0"
    "setResultVisible"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  119,    2, 0x06 /* Public */,
       3,    1,  122,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,  125,    2, 0x0a /* Public */,
       5,    0,  126,    2, 0x0a /* Public */,
       6,    0,  127,    2, 0x0a /* Public */,
       7,    0,  128,    2, 0x0a /* Public */,
       8,    0,  129,    2, 0x0a /* Public */,
       9,    0,  130,    2, 0x0a /* Public */,
      10,    1,  131,    2, 0x0a /* Public */,
      11,    0,  134,    2, 0x0a /* Public */,
      12,    0,  135,    2, 0x0a /* Public */,
      13,    0,  136,    2, 0x0a /* Public */,
      14,    0,  137,    2, 0x0a /* Public */,
      15,    0,  138,    2, 0x0a /* Public */,
      16,    0,  139,    2, 0x0a /* Public */,
      17,    0,  140,    2, 0x0a /* Public */,
      18,    0,  141,    2, 0x0a /* Public */,
      19,    0,  142,    2, 0x0a /* Public */,
      20,    0,  143,    2, 0x0a /* Public */,
      21,    1,  144,    2, 0x0a /* Public */,
      22,    1,  147,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->meshVisible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->resultVisible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->addPolygon(); break;
        case 3: _t->addCircle(); break;
        case 4: _t->deleteEntity(); break;
        case 5: _t->openFile(); break;
        case 6: _t->saveFile(); break;
        case 7: _t->newFile(); break;
        case 8: _t->setMode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->setDrawMode(); break;
        case 10: _t->setMeshMode(); break;
        case 11: _t->setResultMode(); break;
        case 12: _t->showDrawController(); break;
        case 13: _t->showMeshView(); break;
        case 14: _t->showResultController(); break;
        case 15: _t->setMinElementSize(); break;
        case 16: _t->setMaxElementSize(); break;
        case 17: _t->setCustomArguments(); break;
        case 18: _t->resetMeshOptions(); break;
        case 19: _t->setMeshVisible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 20: _t->setResultVisible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::meshVisible)) {
                *result = 0;
            }
        }
        {
            typedef void (MainWindow::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::resultVisible)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 21)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 21;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::meshVisible(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::resultVisible(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
