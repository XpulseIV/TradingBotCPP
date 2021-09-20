#include "iostream"

#define dll __declspec(dllexport)

extern "C"
{
    dll void print(char* str, int len)
    {
        for (int i = 0; i < len; i++)
        {
            std::cout << str[i] << std::endl;
        }
    }

	struct cstr
    {
        const char* str;
        int length;

    	cstr(char* c_p, int len)
    	{
            str = c_p;
            length = len;
    	}
    };

	dll cstr *cPrint(char* c_p, int len)
	{
        cstr* str = new cstr(c_p, len);
        for (int i = 0; i < str->length; i++)
        {
            std::cout << str->str[i] << std::endl;
        }
        return str;
	}

	dll void free_cstr(cstr* p)
	{
        delete p;
	}
}