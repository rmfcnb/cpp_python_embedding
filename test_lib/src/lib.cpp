#include <iostream>
#include <Python.h>
#include <test/lib.h>

void test()
{
    Py_Initialize();
    PyObject* name = PyUnicode_DecodeFSDefault("asdf");
    PyObject* sysPath = PySys_GetObject("path");
    PyObject* path = PyBytes_FromString(".");
    int result = PyList_Insert(sysPath, 0, path);
    PyObject* module = PyImport_Import(name);

    if(module){
        PyObject* func = PyObject_GetAttrString(module, "f");
        if(func != nullptr && PyCallable_Check(func)){
            PyObject* value = PyObject_CallObject(func, PyTuple_Pack(5, 's'));
            std::cout << PyUnicode_AsUTF8(value) << std::endl;
        } else {
            std::cout << "Cannot find function" << std::endl;
        }
    } else {
        std::cout << "Cannot import module" << std::endl;
    }

    Py_Finalize();
}

int main(){
    test();
    return 0;
}