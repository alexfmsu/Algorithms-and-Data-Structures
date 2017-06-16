#pragma once
#include <string>
#include <vector>
class Algorithm
{
public:
	const char* name = "Algorithm";
	std::vector<std::vector<int>> data;
	Algorithm();
	Algorithm(std::vector<std::vector<int>>);
	Algorithm(char*);
	bool LoadData(std::vector<std::vector<int>>);
	bool LoadData(const char*);
	virtual void Run();
protected:
	int GetStrCount(std::ifstream&);
	int GetColCount(std::ifstream&);
	virtual bool validateData();
};

