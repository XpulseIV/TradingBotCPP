#include <iostream>

#include "PythonStuff/cPython.h"

int main()
{
    const cPython pythonHandler;

    const char* filename = "PythonStuff/test.py";
    
    pythonHandler.GetData(filename, "..\dataBTC.csv");
    
    return 0;
}
