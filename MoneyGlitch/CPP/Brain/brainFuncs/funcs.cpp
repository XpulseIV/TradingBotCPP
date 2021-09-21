#include <iostream>
#include "funcs.h"

toBeReturned* BotBrain(int currency_int, float current_price)
{
    auto decision = new toBeReturned{static_cast<currencies>(currency_int), static_cast<actions>(2)};

    std::cout << current_price << std::endl;
    
    return decision;
}