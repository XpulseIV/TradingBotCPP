#include "iostream"

#define funcs __declspec(dllexport)

extern "C"
{
    funcs void print(char* str, int len)
    {
        for (int i = 0; i < len; i++)
        {
            std::cout << str[i] << std::endl;
        }
    }
}