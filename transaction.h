#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <iostream>
#include "movie.h"
#include "bintree.h"
#include "comedy.h"
#include "classic.h"
#include "drama.h"


using namespace std;

class Transaction{

public:

	Transaction();
//	Transaction(const Transaction&);
	virtual ~Transaction();
	virtual void setData(BinTree&, string, char);
	virtual void display() const;
	virtual void doTransaction();
//	virtual Transaction* create();

//	string getMediaTye();
//	string getTransType();
//	Movie* getItem() const;

protected:
	char type;
	string title;
	int year;
};
#endif
