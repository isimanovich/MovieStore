#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <iostream>
#include "movie.h"
using namespace std;

class Customer;
class Transaction {

public:

	Transaction();
	Transaction(const Transaction&);
	virtual ~Transaction();
	virtual bool setData(string, Media*, Customer*);
	virtual void display() const;
	virtual Transaction* doTransaction();

	string getMediaTye();
	string getTransType();
	Media* getItem() const;

protected:
	string transactiontype;
	string mediaType;
	Media* item;
};
#endif
