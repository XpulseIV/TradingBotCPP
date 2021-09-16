#include "cPython.h"

#include <iostream>

void cPython::GetData(const char* filename, const char* filenameOfCSVFile)
{
    Py_Initialize();

    FILE* fp = _Py_fopen(filename, "r");

    PyRun_SimpleFile(fp, filename);
    
    PyObject* moduleMainString = PyUnicode_FromString("__main__");
    PyObject* moduleMain = PyImport_Import(moduleMainString);

    PyObject* func = PyObject_GetAttrString(moduleMain, "getData");
    PyObject* args = PyTuple_Pack(1, PyUnicode_FromString(filenameOfCSVFile));

    PyObject* result = PyObject_CallObject(func, args);

    std::cout << sizeof(result) << std::endl;
    
    Py_Finalize();
}
