#define DLL __declspec(dllexport)
#include "CPP/Brain/Types/Thought/cThought.h"
#include "CPP/Brain/BrainFunctions/funcs.h"

extern "C"
{
    DLL cThought* BotTest(const int currency_int, const float current_price)
    {
        return BotBrain(currency_int, current_price);
    }
    DLL void SetMoney(const int money)
    {
        Money = money;
    }
    DLL void Import(const int currency_int, const float current_price)
    {
        switch(currency_int)
        {
            case 0:
                HistoryRateBTC.push_back(current_price);
                HistoryChangeBTC.push_back(current_price - HistoryChangeBTC.back());
        }
    }
}
