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
	virtual ~Transaction();
	virtual void setData(string, char);
	virtual void doTransaction(BinTree&, char);
	virtual void display() const;


	char getTransType();
	string getTitle();
	int getYear();
	int getMonth();
	string getDirector();
	string getActor();
	bool isSuccess();

protected:
	char type;		//tran
	string title;	//tran
	int year;		//tran
	int month;		//tran
	string director; //tran
	string actor;	//tran
	bool success;

};
#endif
