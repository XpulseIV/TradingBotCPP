#include "iostream"

#define funcs __declspec(dllexport)

extern "C"
{
    funcs void print(const char* str, int len)
    {
        for (int i = 0; i < len; i++)
        {
            std::cout << str[i] << std::endl;
        }
    }
}