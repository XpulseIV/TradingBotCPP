#pragma once
#include <string>
#include <vector>

class cApi
{
public:
    struct cDate
    {
        int Year;
        int Month;
        int Day;
    };
    
    struct cDataCsv
    {
        std::string Currency;
        std::vector<cDate> Dates;
        std::vector<float> Close;
        std::vector<float> Open;
        std::vector<float> Highest;
        std::vector<float> Lowest;
    };


    static cDataCsv ParseCsv(const char* file_name);
};
