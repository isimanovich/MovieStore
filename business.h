// ------------------------------------------------- business.h -----------------------------------------------------
// Name: Ihar Simanovich & Jason Kozodoy
// Course: CSS343 A
// Creation Date: 12/01/2016
// Last Modification: 12/14/2016
// ------------------------------------------------------------------------------------------------------------------
// Purpose:
// ------------------------------------------------------------------------------------------------------------------
// Notes:
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

class Business{
public:
	Business();						//constructor
	~Business();					//destructor
	void buildMovies(ifstream&);
	void buildCustomers();
	void buildCustomers(ifstream&);
	void processTransactions(ifstream&);

private:
	BinTree* allComedies;
	BinTree* allDramas;
	BinTree* allClassics;
	Hash* allCustomers;
};



#endif /* BUSINESS_H_ */
