/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[30];
    char stringdata0[383];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 10), // "csv_signal"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 22), // "std::vector<messpunkt>"
QT_MOC_LITERAL(4, 46, 8), // "csv_data"
QT_MOC_LITERAL(5, 55, 11), // "calc_signal"
QT_MOC_LITERAL(6, 67, 12), // "start_signal"
QT_MOC_LITERAL(7, 80, 4), // "strt"
QT_MOC_LITERAL(8, 85, 13), // "status_signal"
QT_MOC_LITERAL(9, 99, 5), // "state"
QT_MOC_LITERAL(10, 105, 12), // "reset_signal"
QT_MOC_LITERAL(11, 118, 3), // "rst"
QT_MOC_LITERAL(12, 122, 19), // "trafo_matrix_signal"
QT_MOC_LITERAL(13, 142, 10), // "print_slot"
QT_MOC_LITERAL(14, 153, 1), // "x"
QT_MOC_LITERAL(15, 155, 1), // "y"
QT_MOC_LITERAL(16, 157, 1), // "z"
QT_MOC_LITERAL(17, 159, 16), // "print_slot_trafo"
QT_MOC_LITERAL(18, 176, 10), // "state_slot"
QT_MOC_LITERAL(19, 187, 12), // "receive_slot"
QT_MOC_LITERAL(20, 200, 7), // "counter"
QT_MOC_LITERAL(21, 208, 12), // "message_slot"
QT_MOC_LITERAL(22, 221, 11), // "const char*"
QT_MOC_LITERAL(23, 233, 7), // "message"
QT_MOC_LITERAL(24, 241, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(25, 263, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(26, 287, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(27, 311, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(28, 335, 23), // "on_pushButton_5_clicked"
QT_MOC_LITERAL(29, 359, 23) // "on_pushButton_6_clicked"

    },
    "MainWindow\0csv_signal\0\0std::vector<messpunkt>\0"
    "csv_data\0calc_signal\0start_signal\0"
    "strt\0status_signal\0state\0reset_signal\0"
    "rst\0trafo_matrix_signal\0print_slot\0x\0"
    "y\0z\0print_slot_trafo\0state_slot\0"
    "receive_slot\0counter\0message_slot\0"
    "const char*\0message\0on_pushButton_clicked\0"
    "on_pushButton_2_clicked\0on_pushButton_3_clicked\0"
    "on_pushButton_4_clicked\0on_pushButton_5_clicked\0"
    "on_pushButton_6_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x06 /* Public */,
       5,    0,  102,    2, 0x06 /* Public */,
       6,    1,  103,    2, 0x06 /* Public */,
       8,    1,  106,    2, 0x06 /* Public */,
      10,    1,  109,    2, 0x06 /* Public */,
      12,    0,  112,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    3,  113,    2, 0x0a /* Public */,
      17,    3,  120,    2, 0x0a /* Public */,
      18,    1,  127,    2, 0x0a /* Public */,
      19,    1,  130,    2, 0x0a /* Public */,
      21,    1,  133,    2, 0x0a /* Public */,
      24,    0,  136,    2, 0x08 /* Private */,
      25,    0,  137,    2, 0x08 /* Private */,
      26,    0,  138,    2, 0x08 /* Private */,
      27,    0,  139,    2, 0x08 /* Private */,
      28,    0,  140,    2, 0x08 /* Private */,
      29,    0,  141,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double,   14,   15,   16,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double,   14,   15,   16,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, 0x80000000 | 22,   23,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->csv_signal((*reinterpret_cast< std::vector<messpunkt>(*)>(_a[1]))); break;
        case 1: _t->calc_signal(); break;
        case 2: _t->start_signal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->status_signal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->reset_signal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->trafo_matrix_signal(); break;
        case 6: _t->print_slot((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 7: _t->print_slot_trafo((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 8: _t->state_slot((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->receive_slot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->message_slot((*reinterpret_cast< const char*(*)>(_a[1]))); break;
        case 11: _t->on_pushButton_clicked(); break;
        case 12: _t->on_pushButton_2_clicked(); break;
        case 13: _t->on_pushButton_3_clicked(); break;
        case 14: _t->on_pushButton_4_clicked(); break;
        case 15: _t->on_pushButton_5_clicked(); break;
        case 16: _t->on_pushButton_6_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (MainWindow::*_t)(std::vector<messpunkt> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::csv_signal)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::calc_signal)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::start_signal)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::status_signal)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::reset_signal)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::trafo_matrix_signal)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::csv_signal(std::vector<messpunkt> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::calc_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MainWindow::start_signal(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::status_signal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::reset_signal(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MainWindow::trafo_matrix_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
