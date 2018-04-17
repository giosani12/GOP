#ifndef TABLE_H_
#define TABLE_H_

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

#endif TABLE_H_
