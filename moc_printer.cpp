/****************************************************************************
** Meta object code from reading C++ file 'printer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "printer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'printer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_printer_t {
    QByteArrayData data[22];
    char stringdata0[232];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_printer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_printer_t qt_meta_stringdata_printer = {
    {
QT_MOC_LITERAL(0, 0, 7), // "printer"
QT_MOC_LITERAL(1, 8, 12), // "print_signal"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 1), // "x"
QT_MOC_LITERAL(4, 24, 1), // "y"
QT_MOC_LITERAL(5, 26, 1), // "z"
QT_MOC_LITERAL(6, 28, 18), // "print_signal_trafo"
QT_MOC_LITERAL(7, 47, 12), // "state_signal"
QT_MOC_LITERAL(8, 60, 5), // "state"
QT_MOC_LITERAL(9, 66, 14), // "receive_signal"
QT_MOC_LITERAL(10, 81, 7), // "counter"
QT_MOC_LITERAL(11, 89, 14), // "message_signal"
QT_MOC_LITERAL(12, 104, 11), // "const char*"
QT_MOC_LITERAL(13, 116, 7), // "message"
QT_MOC_LITERAL(14, 124, 15), // "calculate_trafo"
QT_MOC_LITERAL(15, 140, 12), // "set_csv_slot"
QT_MOC_LITERAL(16, 153, 22), // "std::vector<messpunkt>"
QT_MOC_LITERAL(17, 176, 3), // "csv"
QT_MOC_LITERAL(18, 180, 10), // "start_slot"
QT_MOC_LITERAL(19, 191, 11), // "status_slot"
QT_MOC_LITERAL(20, 203, 10), // "reset_slot"
QT_MOC_LITERAL(21, 214, 17) // "trafo_matrix_slot"

    },
    "printer\0print_signal\0\0x\0y\0z\0"
    "print_signal_trafo\0state_signal\0state\0"
    "receive_signal\0counter\0message_signal\0"
    "const char*\0message\0calculate_trafo\0"
    "set_csv_slot\0std::vector<messpunkt>\0"
    "csv\0start_slot\0status_slot\0reset_slot\0"
    "trafo_matrix_slot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_printer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   69,    2, 0x06 /* Public */,
       6,    3,   76,    2, 0x06 /* Public */,
       7,    1,   83,    2, 0x06 /* Public */,
       9,    1,   86,    2, 0x06 /* Public */,
      11,    1,   89,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    0,   92,    2, 0x0a /* Public */,
      15,    1,   93,    2, 0x0a /* Public */,
      18,    0,   96,    2, 0x0a /* Public */,
      19,    1,   97,    2, 0x0a /* Public */,
      20,    0,  100,    2, 0x0a /* Public */,
      21,    0,  101,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double,    3,    4,    5,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double,    3,    4,    5,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, 0x80000000 | 12,   13,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void printer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        printer *_t = static_cast<printer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->print_signal((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 1: _t->print_signal_trafo((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 2: _t->state_signal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->receive_signal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->message_signal((*reinterpret_cast< const char*(*)>(_a[1]))); break;
        case 5: _t->calculate_trafo(); break;
        case 6: _t->set_csv_slot((*reinterpret_cast< std::vector<messpunkt>(*)>(_a[1]))); break;
        case 7: _t->start_slot(); break;
        case 8: _t->status_slot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->reset_slot(); break;
        case 10: _t->trafo_matrix_slot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (printer::*_t)(double , double , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&printer::print_signal)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (printer::*_t)(double , double , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&printer::print_signal_trafo)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (printer::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&printer::state_signal)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (printer::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&printer::receive_signal)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (printer::*_t)(const char * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&printer::message_signal)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject printer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_printer.data,
      qt_meta_data_printer,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *printer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *printer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_printer.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int printer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void printer::print_signal(double _t1, double _t2, double _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void printer::print_signal_trafo(double _t1, double _t2, double _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void printer::state_signal(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void printer::receive_signal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void printer::message_signal(const char * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
