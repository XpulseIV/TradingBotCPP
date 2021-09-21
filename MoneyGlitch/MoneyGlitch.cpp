#define DLL __declspec(dllexport)
#include "CPP/Brain/structs/toBeReturned/toBeReturned.h"
#include "CPP/Brain/brainFuncs/funcs.h"

extern "C"
{
    DLL toBeReturned* BotTest(const int currency_int, const float current_price)
    {
        return BotBrain(currency_int, current_price);
    }
}
