#include <iostream>

#include "api/cApi.h"

int main(int argc, char* argv[])
{
    auto api = cApi();
    const auto csvData = api.ParseCsv("dataBTC.csv");
    
    return 0;
}
