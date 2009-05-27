#include "Test.h"

#include <boost/shared_ptr.hpp>
#include <Python.h>

#include "PyTest.h"
using namespace std;


void modifySysPath ()
{
    // Enter the current working directory into the python module path
    //
    char *cwd = get_current_dir_name();
    printf("  Adding %s to sys.path\n", cwd);

    PyObject *sys_module = PyImport_ImportModule("sys");
    if (sys_module == NULL) {
        fprintf(stderr, "** Error importing sys module: **");
        if (PyErr_Occurred())
            PyErr_Print();
        else
            fprintf(stderr, "** No Python exception information available **");
    }else {
        PyObject *dict = PyModule_GetDict(sys_module);
        PyObject *path = PyDict_GetItemString(dict, "path");
        PyList_Append(path, PyString_FromString(cwd));
        Py_DECREF(sys_module);
    }

    free(cwd);

}


int main(){

    boost::shared_ptr<Test> test  = boost::shared_ptr<Test>(new Test());
    set_test_pointer(test);
    c_init_test();

    modifySysPath();

    
    PyObject *foo_module = PyImport_ImportModule("Foo");

    if (foo_module == NULL){
        if (PyErr_Occurred())
            PyErr_Print();
        std::cout << "Fml" <<std::endl;
        return 1;
    }
   
    PyObject *dict = PyModule_GetDict(foo_module);
    PyObject *foo_class = PyDict_GetItemString(dict, "Foo");

    PyObject *foo_instance = PyObject_CallObject(foo_class, NULL);
    if (PyErr_Occurred())
        PyErr_Print();
    cout << "Calling method in python" <<endl;
    PyObject_CallMethod(foo_instance, "sendAndPrint", NULL);
    if (PyErr_Occurred())
        PyErr_Print();
}



