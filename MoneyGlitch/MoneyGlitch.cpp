#define DLL __declspec(dllexport)
#include "CPP/Brain/structs/toBeReturned/toBeReturned.h"
#include "CPP/Brain/brainFuncs/funcs.h"

extern "C"
{
    DLL cToBeReturned* BotEntryPointPython(const int currency_int, const float current_price)
    {
        return BotEntryPoint(currency_int, current_price);
    }
}
