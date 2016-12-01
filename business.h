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

using namespace std;

class Business{
public:
	Business();						//constructor
	~Business();					//destructor
	void buildMovies(ifstream&);				//add infile
	void buildCustomers();			//add infile
	void processTransactions();		//add infile

private:
	BinTree* allComedies;
	BinTree* allDramas;
	BinTree* allClassics;
	//HashTable* allCustomers;
	Transaction* currentTransaction;

};



#endif /* BUSINESS_H_ */
