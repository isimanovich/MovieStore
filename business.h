/*
 * Business.h
 *
 *  Created on: Nov 30, 2016
 *      Author: MacBook
 */

#ifndef BUSINESS_H_
#define BUSINESS_H_

using namespace std;

class Business{
public:
	void buildMovies();
	void buildCustomers();
	void processTrans();

private:
	BinTree* allComedies;
	BinTree* allDramas;
	BinTree* allClassics;
	//HashTable* allCustomers;
	Transaction* currentTransaction;

};



#endif /* BUSINESS_H_ */
