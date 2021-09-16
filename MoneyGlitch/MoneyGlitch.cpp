#include <iostream>

#include "api/cApi.h"

int main()
{
    auto cApii = new cApi();

    auto data = cApii->ParseCsv("dataBTC.csv");
    
    for (auto& as : data.Dates) std::cout << as.Year << std::endl;
    return 0;
}
