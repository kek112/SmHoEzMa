/****************************************************************************
** Meta object code from reading C++ file 'devicelistview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/devicelistview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'devicelistview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CDeviceListView_t {
    QByteArrayData data[12];
    char stringdata0[147];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CDeviceListView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CDeviceListView_t qt_meta_stringdata_CDeviceListView = {
    {
QT_MOC_LITERAL(0, 0, 15), // "CDeviceListView"
QT_MOC_LITERAL(1, 16, 11), // "startThread"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 12), // "SleepDevices"
QT_MOC_LITERAL(4, 42, 13), // "OpenAddDevice"
QT_MOC_LITERAL(5, 56, 12), // "RemoveDevice"
QT_MOC_LITERAL(6, 69, 15), // "CancelAddDevice"
QT_MOC_LITERAL(7, 85, 9), // "AddDevice"
QT_MOC_LITERAL(8, 95, 24), // "CDeviceStructure::Device"
QT_MOC_LITERAL(9, 120, 6), // "_toAdd"
QT_MOC_LITERAL(10, 127, 11), // "ReachedHome"
QT_MOC_LITERAL(11, 139, 7) // "_device"

    },
    "CDeviceListView\0startThread\0\0SleepDevices\0"
    "OpenAddDevice\0RemoveDevice\0CancelAddDevice\0"
    "AddDevice\0CDeviceStructure::Device\0"
    "_toAdd\0ReachedHome\0_device"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CDeviceListView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   50,    2, 0x0a /* Public */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    1,   54,    2, 0x08 /* Private */,
      10,    1,   57,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::Int,   11,

       0        // eod
};

void CDeviceListView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CDeviceListView *_t = static_cast<CDeviceListView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->startThread(); break;
        case 1: _t->SleepDevices(); break;
        case 2: _t->OpenAddDevice(); break;
        case 3: _t->RemoveDevice(); break;
        case 4: _t->CancelAddDevice(); break;
        case 5: _t->AddDevice((*reinterpret_cast< CDeviceStructure::Device(*)>(_a[1]))); break;
        case 6: _t->ReachedHome((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CDeviceListView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CDeviceListView::startThread)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CDeviceListView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CDeviceListView.data,
      qt_meta_data_CDeviceListView,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CDeviceListView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CDeviceListView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CDeviceListView.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CDeviceListView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void CDeviceListView::startThread()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
