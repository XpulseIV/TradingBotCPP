#pragma once
#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <stdio.h>
#include <conio.h>
#include <string>
#include <stdlib.h>

class cPython
{
public:
    static void GetData(const char* filename, const char* filenameOfCSVFile);
};
