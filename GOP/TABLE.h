#ifndef TABLE_H_
#define TABLE_H_

class GLOBAL;
class TABLE;
typedef TABLE* ptTABLE;

class TABLE : public GLOBAL
{
protected:
	int pt[60];
	bool valid;
public:
	int lenght;
	TABLE(int);
	~TABLE();
	int getType(int);
	void printTable();
};

#endif
