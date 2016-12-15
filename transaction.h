// ---------------------------------------------- transaction.h -----------------------------------------------------
// Name: Ihar Simanovich & Jason Kozodoy
// Course: CSS343 A
// Creation Date: 12/01/2016
// Last Modification: 12/14/2016
// ------------------------------------------------------------------------------------------------------------------
#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <iostream>
#include "movie.h"
#include "bintree.h"
#include "comedy.h"
#include "classic.h"
#include "drama.h"

using namespace std;

//Transaction class.
//represents a transaction that customer makes
class Transaction{

public:

	Transaction();
	virtual ~Transaction();

	//business logic functions
	virtual void setData(string, char);
	virtual void doTransaction(BinTree&, char);

	//getters functions
	char getTransType();
	string getTitle();
	int getYear();
	int getMonth();
	string getDirector();
	string getActor();
	bool isSuccess();

protected:
	char type;
	string title;
	int year;
	int month;
	string director;
	string actor;
	bool success;

};
#endif
