/****************************************************************************
** Meta object code from reading C++ file 'deviceview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/deviceview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'deviceview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CDeviceView_t {
    QByteArrayData data[10];
    char stringdata0[132];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CDeviceView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CDeviceView_t qt_meta_stringdata_CDeviceView = {
    {
QT_MOC_LITERAL(0, 0, 11), // "CDeviceView"
QT_MOC_LITERAL(1, 12, 13), // "DeviceChanged"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 24), // "CDeviceStructure::Device"
QT_MOC_LITERAL(4, 52, 7), // "_device"
QT_MOC_LITERAL(5, 60, 12), // "UpdateDevice"
QT_MOC_LITERAL(6, 73, 11), // "ReachedHome"
QT_MOC_LITERAL(7, 85, 15), // "SettingsChanged"
QT_MOC_LITERAL(8, 101, 14), // "UpdatePosition"
QT_MOC_LITERAL(9, 116, 15) // "OpenColorDialog"

    },
    "CDeviceView\0DeviceChanged\0\0"
    "CDeviceStructure::Device\0_device\0"
    "UpdateDevice\0ReachedHome\0SettingsChanged\0"
    "UpdatePosition\0OpenColorDialog"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CDeviceView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   47,    2, 0x0a /* Public */,
       6,    0,   50,    2, 0x0a /* Public */,
       7,    0,   51,    2, 0x0a /* Public */,
       8,    0,   52,    2, 0x0a /* Public */,
       9,    0,   53,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CDeviceView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CDeviceView *_t = static_cast<CDeviceView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->DeviceChanged((*reinterpret_cast< CDeviceStructure::Device(*)>(_a[1]))); break;
        case 1: _t->UpdateDevice((*reinterpret_cast< CDeviceStructure::Device(*)>(_a[1]))); break;
        case 2: _t->ReachedHome(); break;
        case 3: _t->SettingsChanged(); break;
        case 4: _t->UpdatePosition(); break;
        case 5: _t->OpenColorDialog(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CDeviceView::*)(CDeviceStructure::Device );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CDeviceView::DeviceChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CDeviceView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CDeviceView.data,
      qt_meta_data_CDeviceView,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CDeviceView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CDeviceView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CDeviceView.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CDeviceView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void CDeviceView::DeviceChanged(CDeviceStructure::Device _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
