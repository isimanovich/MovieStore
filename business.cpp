/*
 * business.cpp
 *
 *  Created on: Dec 1, 2016
 *      Author: MacBook
 */

#include "business.h"

//constructor
Business::Business(){

	//creating pointers for every type of movies
	allComedies = new BinTree();
	allDramas = new BinTree();
	allClassics = new BinTree();


	//not sure about this one
	currentTransaction = new Transaction();
}

//destructor
Business::~Business(){
	allComedies->makeEmpty();	//making tree empty
	delete allComedies;			//deleting pointer SET TO NULL? MAYBE NOT NEEDED
	allDramas->makeEmpty();		//making tree empty
	delete allDramas;			//deleting pointer SET TO NULL? MAYBE NOT NEEDED
	allClassics->makeEmpty();	//making tree empty
	delete allClassics;			//deleting pointer SET TO NULL? MAYBE NOT NEEDED

	//need to delete current transaction, just deleting pointer???
	//SHOULD TRANSACTION HAVE STORAGE FOR ALL TRANSACTIONS???
	//THEN NEED TO DELETE THAT DATA
	//delete currentTransaction;

}


//SHOULD ACCEPT INFILE, FIX THAT
void Business::buildMovies(){
	//logic for reading file and adding stuff to the tree
}

//SHOULD ACCEPT INFILE, FIX THAT
void Business::buildCustomers(){
	//logic for reading file and adding stuff to the tree
}

//SHOULD ACCEPT INFILE, FIX THAT
void Business::processTransactions(){
	//logic for reading file and adding stuff to the tree
}



