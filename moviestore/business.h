// ------------------------------------------------- business.h -----------------------------------------------------
// Name: Ihar Simanovich & Jason Kozodoy
// Course: CSS343 A
// Creation Date: 12/01/2016
// Last Modification: 12/14/2016
// ------------------------------------------------------------------------------------------------------------------

#ifndef BUSINESS_H_
#define BUSINESS_H_

#include <fstream>
#include <iostream>
#include "bintree.h"
#include "transaction.h"
#include "borrow.h"
#include "return.h"
#include "movie.h"
#include "comedy.h"
#include "classic.h"
#include "drama.h"
#include "customer.h"
#include "hash.h"

using namespace std;

//represents our business
//that deals with movies
class Business{
public:
	Business();						//constructor
	~Business();					//destructor
	void buildMovies(ifstream&); //build our movies
	void buildCustomers();   //build customers
	void buildCustomers(ifstream&); //build customers
	void processTransactions(ifstream&); //process transactions

private:
	BinTree* allComedies; //comedy movies
	BinTree* allDramas; //drama movies
	BinTree* allClassics; //classic movies
	Hash* allCustomers; //customers
};



#endif /* BUSINESS_H_ */
