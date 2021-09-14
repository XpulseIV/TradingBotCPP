#include "cApi.h"

#include <fstream>
#include <iostream>

cApi::cDataCsv cApi::ParseCsv(const std::string& file_name)
{
    cDataCsv data; //The data
    std::string line; //Line
    std::vector<std::string> lines; //Vector of all lines in file
    
    auto csvStream = std::ifstream(file_name); //Open file

    while (std::getline(csvStream, line)) lines.push_back(line); //Go through file and add all lines to lines Vector
    
    data.Currency = lines[1].substr(0, 3); //Set the currency
    
    for (int i = 1; i < lines.size(); i++) //Parsing
    {
        const int firstComma = lines[i].find(",", 15); //Position in line of first comma
        const int secondComma = lines[i].find(",", firstComma+1); //Position in line of second comma
        const int thirdComma = lines[i].find(",", secondComma+1); //Position in line of third comma
        

        data.Dates.push_back(cDate{std::stoi(lines[i].substr(4, 4)), std::stoi(lines[i].substr(9, 2)), std::stoi(lines[i].substr(12, 2))}); //Find all the data pertaining to the date
        data.Close.push_back(stof(lines[i].substr(15, firstComma))); //Find close price
        data.Open.push_back(stof(lines[i].substr(firstComma+1, secondComma - firstComma))); //Find open price
        data.Highest.push_back(std::stof(lines[i].substr(secondComma+1, thirdComma - secondComma))); //Find highest price
        data.Lowest.push_back(std::stof(lines[i].substr(thirdComma+1))); //Find lowest price
    }
    
    return data; //Return the data in a big class
}
