
#ifndef RETURN_H
#define RETURN_H
#include "transaction.h"
using namespace std;

class Return: public Transaction
{
public:
	Return();
//	Return(const Return&);
	~Return();
	void setData(BinTree&, string);
	void display() const;
//	virtual Transaction* create();
};
#endif
