#include <iostream>
#include "funcs.h"

cToBeReturned* BotEntryPoint(int currency_int, float current_price)
{
	const auto decision = new cToBeReturned{static_cast<currencies>(currency_int), static_cast<actions>(2)};

    int result = 0;

	#pragma region Bot_Logic



	#pragma endregion
    
    decision->Action = static_cast<actions>(result);
    
    return decision;
}