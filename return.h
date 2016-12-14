
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
	void setData(string, char);
	void doTransaction(BinTree&, char);
	bool isSuccess();
//	virtual Transaction* create();

};
#endif
