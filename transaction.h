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
	virtual bool setData(string, Movie*, Customer*);
	virtual void display() const;
	virtual Transaction* create();

	string getMediaTye();
	string getTransType();
	Movie* getItem() const;

protected:
	string transactiontype;
	string mediaType;
	Movie* item;
};
#endif
