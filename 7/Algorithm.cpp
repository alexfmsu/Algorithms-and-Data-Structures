#include "Algorithm.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
Algorithm::Algorithm() {}
//load functions
Algorithm::Algorithm(std::vector<std::vector<int>> Data)
{
    LoadData(Data);
}
Algorithm::Algorithm(char* Path)
{
    LoadData(Path);
}
int Algorithm::GetStrCount(ifstream &file)
{
    int count = 0;
    while (!file.eof()) {
        file.getline(new char[255], 255);
        count++;
    };
    file.seekg(0);
    return count;
}
int Algorithm::GetColCount(ifstream &file)
{
    int count = 0;
    char str[255];
    file.getline(str, 255);
    for (int i = 0; i < strlen(str); i++)
    {
        if (isdigit(str[i]))
            if (i != 0 && !isdigit(str[i - 1]))
                count++;
            else if (i == 0)
                count++;
    }
    file.seekg(0);
    return count;
}
bool Algorithm::LoadData(vector<vector<int>> Data)
{
    data = Data;
    return true;
}
bool Algorithm::LoadData(const char* Path)
{
    ifstream file(Path, ios_base::in);
    if (!file.is_open()) throw "Can't open data file";
    int rows = GetStrCount(file), cols = GetColCount(file);
    for(int i = 0; i < rows; i++)
    {
        vector<int> temp;
        for(int j = 0; j < cols; j++)
        {
            int n;
            file >> n;
            temp.push_back(n);
        }
        data.push_back(vector<int>(temp));
    }
    file.seekg(0);
    return true;
}
//virtual functions
bool Algorithm::validateData() 
{
    return true;
}
void Algorithm::Run() 
{
    system("cls");
    if (!validateData()) throw "Not valid data.";
    std::cout << name << ":" << std::endl;
}

