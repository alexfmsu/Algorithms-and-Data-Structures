#pragma once
#include "Algorithm.h"
using namespace std;
class LittleAlgorithm : public Algorithm
{
public:
    vector<pair<int,int>> result;
    LittleAlgorithm();
    LittleAlgorithm(vector<vector<int>>);
    LittleAlgorithm(char*);
    virtual void Run();
private:
    enum check{Row, Col};
    int getMin(vector<vector<int>>, int, check);
    void matrixProcedure(vector<vector<int>>);
    void showMatrix(vector<vector<int>>);
    int getResultSum();
    virtual bool validateData();
};

