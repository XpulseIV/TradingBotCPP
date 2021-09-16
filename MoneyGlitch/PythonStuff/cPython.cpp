#include "cPython.h"

void cPython::RunPythonFile(const char* filename)
{
    FILE* fp;

    Py_Initialize();

    fp = _Py_fopen(filename, "r");
    PyRun_SimpleFile(fp, filename);

    Py_Finalize();
}

