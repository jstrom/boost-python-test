#include "PyTest.h"

#include <Python.h>
#include <boost/python.hpp>
using namespace boost::python;

#include <boost/shared_ptr.hpp>
using boost::shared_ptr;

#include "Test.h"

shared_ptr<Test> test_pointer;

// Note the use of "class_<RoboGuardian, shared_ptr<RoboGuardian> >".
// It means that Python will be happy to treat shared pointers to RoboGuardin
// as real objects rather than pointers and it will not encroach on the shared
// pointer's built-in reference counter.
BOOST_PYTHON_MODULE(_test)
{
    class_<Test, shared_ptr<Test> >("Test", no_init)
        .def("setInt", &Test::setInt)
        .def("printInt", &Test::printInt)
        ;

    scope().attr("test") = test_pointer;
}


void c_init_test () {
    if (!Py_IsInitialized())
        Py_Initialize();

    try {
        init_test();
    } catch (error_already_set) {
        PyErr_Print();
    }

}

void set_test_pointer (shared_ptr<Test> _test_ptr) {
    test_pointer = _test_ptr;
}
