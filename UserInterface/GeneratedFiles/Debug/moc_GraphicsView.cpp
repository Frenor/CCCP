/****************************************************************************
** Meta object code from reading C++ file 'GraphicsView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../GraphicsView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GraphicsView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GraphicsView_t {
    QByteArrayData data[11];
    char stringdata[138];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GraphicsView_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GraphicsView_t qt_meta_stringdata_GraphicsView = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 9),
QT_MOC_LITERAL(2, 23, 0),
QT_MOC_LITERAL(3, 24, 11),
QT_MOC_LITERAL(4, 36, 12),
QT_MOC_LITERAL(5, 49, 25),
QT_MOC_LITERAL(6, 75, 18),
QT_MOC_LITERAL(7, 94, 13),
QT_MOC_LITERAL(8, 108, 12),
QT_MOC_LITERAL(9, 121, 5),
QT_MOC_LITERAL(10, 127, 10)
    },
    "GraphicsView\0doneEvent\0\0cancelEvent\0"
    "actorClicked\0vtkSmartPointer<vtkActor>\0"
    "actorDoubleClicked\0escapePressed\0"
    "enterPressed\0reset\0invalidate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GraphicsView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,
       4,    1,   56,    2, 0x06 /* Public */,
       6,    1,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   62,    2, 0x0a /* Public */,
       8,    0,   63,    2, 0x0a /* Public */,
       9,    0,   64,    2, 0x0a /* Public */,
      10,    0,   65,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 5,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GraphicsView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GraphicsView *_t = static_cast<GraphicsView *>(_o);
        switch (_id) {
        case 0: _t->doneEvent(); break;
        case 1: _t->cancelEvent(); break;
        case 2: _t->actorClicked((*reinterpret_cast< vtkSmartPointer<vtkActor>(*)>(_a[1]))); break;
        case 3: _t->actorDoubleClicked((*reinterpret_cast< vtkSmartPointer<vtkActor>(*)>(_a[1]))); break;
        case 4: _t->escapePressed(); break;
        case 5: _t->enterPressed(); break;
        case 6: _t->reset(); break;
        case 7: _t->invalidate(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GraphicsView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GraphicsView::doneEvent)) {
                *result = 0;
            }
        }
        {
            typedef void (GraphicsView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GraphicsView::cancelEvent)) {
                *result = 1;
            }
        }
        {
            typedef void (GraphicsView::*_t)(vtkSmartPointer<vtkActor> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GraphicsView::actorClicked)) {
                *result = 2;
            }
        }
        {
            typedef void (GraphicsView::*_t)(vtkSmartPointer<vtkActor> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GraphicsView::actorDoubleClicked)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject GraphicsView::staticMetaObject = {
    { &QVTKWidget::staticMetaObject, qt_meta_stringdata_GraphicsView.data,
      qt_meta_data_GraphicsView,  qt_static_metacall, 0, 0}
};


const QMetaObject *GraphicsView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GraphicsView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GraphicsView.stringdata))
        return static_cast<void*>(const_cast< GraphicsView*>(this));
    return QVTKWidget::qt_metacast(_clname);
}

int GraphicsView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QVTKWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void GraphicsView::doneEvent()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void GraphicsView::cancelEvent()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void GraphicsView::actorClicked(vtkSmartPointer<vtkActor> _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void GraphicsView::actorDoubleClicked(vtkSmartPointer<vtkActor> _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
