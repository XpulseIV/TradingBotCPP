#define DLL __declspec(dllexport)
#include "CPP/Brain/Types/Thought/cAction.h"
#include "CPP/Brain/BrainFunctions/funcs.h"

int Money;
// BITCOIN
std::vector<float> HistoryRateBTC;
std::vector<float> HistoryChangeBTC;

extern "C"
{
    DLL void BotEntryPoint(const int money)
    {
        Money = money;
    }

    DLL cAction* GetThought(const int currency_int, const float rate_float)
    {
        return BotBrain(currency_int, rate_float);
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
