
#ifndef RETURN_H
#define RETURN_H
#include "media.h"
#include "transaction.h"
using namespace std;


class Customer;
class Return: public Transaction
{
public:
	Return();
	Return(const Return&);
	virtual ~Return();
	virtual bool setData(string, Media*, Customer*);
	virtual void display() const;
	virtual Transaction* create();
};
#endif
