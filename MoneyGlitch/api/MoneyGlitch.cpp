#include "iostream"

extern "C"
{
    __declspec(dllexport) void print(const char* str, int len)
    {
        for (int i = 0; i < len; i++)
        {
            std::cout << str[i] << std::endl;
        }
    }
}