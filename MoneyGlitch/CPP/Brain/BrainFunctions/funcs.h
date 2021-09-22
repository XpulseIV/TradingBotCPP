#pragma once
#include <vector>
#include "../Types/Thought/cThought.h"

cThought* BotBrain(int currency_int, float current_price);

int Money;

// BITCOIN
std::vector<float> HistoryRateBTC;
std::vector<float> HistoryChangeBTC;