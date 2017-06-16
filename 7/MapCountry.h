#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <iterator>

enum TypeError
{
    ALL_IS_SUCCESS
    , ERROR
    , INCORRECTLY_CALLED_COMMAND
};

struct SRoard
{
    int from;
    int to;
};


class CMapCountry
{
public:
    CMapCountry(std::vector<int> const &numberRoads)
        : m_numberRoadsLeavingCitys(numberRoads)
    {}
    void ConstructNewRoads();
    std::vector<SRoard> GetNewRoadsList() const;
private:
    std::vector<int> m_numberRoadsLeavingCitys;
    std::vector<SRoard> m_newRoads;
};