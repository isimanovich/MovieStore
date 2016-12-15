// ---------------------------------------------- transaction.h -----------------------------------------------------
// Name: Ihar Simanovich & Jason Kozodoy
// Course: CSS343 A
// Creation Date: 12/01/2016
// Last Modification: 12/14/2016
// ------------------------------------------------------------------------------------------------------------------
// Purpose:
// ------------------------------------------------------------------------------------------------------------------
// Notes:
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
	char type;		//tran
	string title;	//tran
	int year;		//tran
	int month;		//tran
	string director; //tran
	string actor;	//tran
	bool success;

};
#endif
