#include <iostream>
#include "funcs.h"

cThought* BotBrain(int currency_int, float current_price)
{
    auto decision = new cThought{static_cast<currencies>(currency_int), static_cast<actions>(2)};

    std::cout << current_price << std::endl;
    
    return decision;
}