#include "cApi.h"

#include <fstream>
#include <iostream>

cApi::cDataCsv cApi::ParseCsv(const std::string& file_name)
{
    cDataCsv data;
    std::string line;

    constexpr currencies currency = BTC;
    
    auto csvStream = std::ifstream(file_name);

    while (std::getline(csvStream, line))
    {
        if (line[0] == 'C') continue;
        const int firstComma = line.find(",", 15);
        const int secondComma = line.find(",", firstComma+1);
        const int thirdComma = line.find(",", secondComma+1);

        data.Currency = currency;

        data.Dates.push_back(cDate{std::stoi(line.substr(4, 4)), std::stoi(line.substr(9, 2)), std::stoi(line.substr(12, 2))});
        data.Close.push_back(stof(line.substr(15, firstComma)));
        data.Open.push_back(stof(line.substr(firstComma+1, secondComma - firstComma)));
        data.Highest.push_back(std::stof(line.substr(secondComma+1, thirdComma - secondComma)));
        data.Lowest.push_back(std::stof(line.substr(thirdComma+1)));
    }
    
    return data;
}
