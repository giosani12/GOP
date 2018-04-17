#pragma once
class TABLE
{
private:
	int lenght;
	int pt[60];
	bool valid;
public:
	TABLE(int);
	~TABLE();
	int getType(int);
	void printTable();
};

