#include <iostream>

#include "PythonStuff/cPython.h"

int main()
{
    const cPython pythonStuff;

    const char* filename = "PythonStuff/main.py";
    
    pythonStuff.getData(filename);
    
    return 0;
}
