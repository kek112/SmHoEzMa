/****************************************************************************
** Meta object code from reading C++ file 'mainview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/mainview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CMainView_t {
    QByteArrayData data[11];
    char stringdata0[114];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CMainView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CMainView_t qt_meta_stringdata_CMainView = {
    {
QT_MOC_LITERAL(0, 0, 9), // "CMainView"
QT_MOC_LITERAL(1, 10, 17), // "sendIsMenuVisible"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 8), // "_visible"
QT_MOC_LITERAL(4, 38, 11), // "triggerMenu"
QT_MOC_LITERAL(5, 50, 9), // "closeMenu"
QT_MOC_LITERAL(6, 60, 11), // "_sendSignal"
QT_MOC_LITERAL(7, 72, 8), // "openMenu"
QT_MOC_LITERAL(8, 81, 11), // "ShowDevices"
QT_MOC_LITERAL(9, 93, 9), // "ShowAbout"
QT_MOC_LITERAL(10, 103, 10) // "SleepModus"

    },
    "CMainView\0sendIsMenuVisible\0\0_visible\0"
    "triggerMenu\0closeMenu\0_sendSignal\0"
    "openMenu\0ShowDevices\0ShowAbout\0"
    "SleepModus"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CMainView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   57,    2, 0x08 /* Private */,
       5,    1,   58,    2, 0x08 /* Private */,
       5,    0,   61,    2, 0x28 /* Private | MethodCloned */,
       7,    0,   62,    2, 0x08 /* Private */,
       8,    0,   63,    2, 0x08 /* Private */,
       9,    0,   64,    2, 0x08 /* Private */,
      10,    0,   65,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CMainView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CMainView *_t = static_cast<CMainView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendIsMenuVisible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->triggerMenu(); break;
        case 2: _t->closeMenu((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->closeMenu(); break;
        case 4: _t->openMenu(); break;
        case 5: _t->ShowDevices(); break;
        case 6: _t->ShowAbout(); break;
        case 7: _t->SleepModus(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (CMainView::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CMainView::sendIsMenuVisible)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CMainView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CMainView.data,
      qt_meta_data_CMainView,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CMainView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CMainView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CMainView.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CMainView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void CMainView::sendIsMenuVisible(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
