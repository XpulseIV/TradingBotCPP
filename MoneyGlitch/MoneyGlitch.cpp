#include <iostream>

#include "PythonStuff/cPython.h"

int main(int argc, char* argv[])
{
    const cPython pythonStuff;

    const char* filename = "C:\\LEL\\LEL\\main.py";
    
    pythonStuff.RunPythonFile(filename);
    
    return 0;
}
