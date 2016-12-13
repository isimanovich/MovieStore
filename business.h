/*
 * Business.h
 *
 *  Created on: Nov 30, 2016
 *      Author: MacBook
 */

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


//DON'T FORGET TO ADD BORROW RETURN ETC .h FILES



using namespace std;

class Business{
public:
	Business();						//constructor
	~Business();					//destructor
	void buildMovies(ifstream&);				//add infile
	void buildCustomers();			//add infile
	void buildCustomers(ifstream&);			//add infile
	void processTransactions(ifstream&);		//add infile

private:
	BinTree* allComedies;
	BinTree* allDramas;
	BinTree* allClassics;

	//Stack* history;

	//HashTable* allCustomers;
//	Transaction* currentTransaction;

};



#endif /* BUSINESS_H_ */
