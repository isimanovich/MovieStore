#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <iostream>
#include "movie.h"
#include "bintree.h"
//#include "business.h"
using namespace std;
class Business;
class Transaction{

public:

	Transaction();
	Transaction(const Transaction&);
	virtual ~Transaction();
	virtual void setData(string);
	virtual void display() const;
//	virtual Transaction* create();

//	string getMediaTye();
//	string getTransType();
//	Movie* getItem() const;

protected:
//	string transactiontype;
//	string mediaType;
//	Movie* item;
};
#endif
