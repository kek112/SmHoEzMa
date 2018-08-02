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
    QByteArrayData data[15];
    char stringdata0[207];
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
QT_MOC_LITERAL(5, 60, 8), // "DebugMap"
QT_MOC_LITERAL(6, 69, 12), // "UpdateDevice"
QT_MOC_LITERAL(7, 82, 11), // "ReachedHome"
QT_MOC_LITERAL(8, 94, 15), // "SettingsChanged"
QT_MOC_LITERAL(9, 110, 14), // "UpdatePosition"
QT_MOC_LITERAL(10, 125, 15), // "OpenColorDialog"
QT_MOC_LITERAL(11, 141, 11), // "SleepDevice"
QT_MOC_LITERAL(12, 153, 24), // "QuickWidgetStatusChanged"
QT_MOC_LITERAL(13, 178, 20), // "QQuickWidget::Status"
QT_MOC_LITERAL(14, 199, 7) // "_status"

    },
    "CDeviceView\0DeviceChanged\0\0"
    "CDeviceStructure::Device\0_device\0"
    "DebugMap\0UpdateDevice\0ReachedHome\0"
    "SettingsChanged\0UpdatePosition\0"
    "OpenColorDialog\0SleepDevice\0"
    "QuickWidgetStatusChanged\0QQuickWidget::Status\0"
    "_status"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CDeviceView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       5,    0,   62,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   63,    2, 0x0a /* Public */,
       7,    0,   66,    2, 0x0a /* Public */,
       8,    0,   67,    2, 0x0a /* Public */,
       9,    0,   68,    2, 0x0a /* Public */,
      10,    0,   69,    2, 0x0a /* Public */,
      11,    0,   70,    2, 0x0a /* Public */,
      12,    1,   71,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,

       0        // eod
};

void CDeviceView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CDeviceView *_t = static_cast<CDeviceView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->DeviceChanged((*reinterpret_cast< CDeviceStructure::Device(*)>(_a[1]))); break;
        case 1: _t->DebugMap(); break;
        case 2: _t->UpdateDevice((*reinterpret_cast< CDeviceStructure::Device(*)>(_a[1]))); break;
        case 3: _t->ReachedHome(); break;
        case 4: _t->SettingsChanged(); break;
        case 5: _t->UpdatePosition(); break;
        case 6: _t->OpenColorDialog(); break;
        case 7: _t->SleepDevice(); break;
        case 8: _t->QuickWidgetStatusChanged((*reinterpret_cast< QQuickWidget::Status(*)>(_a[1]))); break;
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
        {
            using _t = void (CDeviceView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CDeviceView::DebugMap)) {
                *result = 1;
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
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void CDeviceView::DeviceChanged(CDeviceStructure::Device _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CDeviceView::DebugMap()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
