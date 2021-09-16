#include "cPython.h"

#include <iostream>

void cPython::getData(const char* filename)
{
    Py_Initialize();

    PyObject* myModuleString = PyBytes_FromString((char*)"main");
    PyObject* myModule = PyImport_Import(myModuleString);

    PyObject* myFunction = PyObject_GetAttrString(myModule,(char*)"testFunc");
    PyObject* args = PyTuple_Pack(1,2);

    PyObject* myResult = PyObject_CallObject(myFunction, args);

    double result = PyFloat_AsDouble(myResult);
    
    Py_Finalize();
}
