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
	currentTransaction = NULL;
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


void Business::buildMovies(ifstream& movFile){

	/*string test = ", 10, Barry Levinson, Good Morning Vietnam, 1988 /n";
	Movie* d = new Movie();
	d->setData(test);*/

	char type = 'z';
	string restOfLine;

	while(!movFile.eof()){
		movFile >> type;
		getline(movFile,restOfLine);
		switch(type){

		case 'F':
			Movie* movie1 = new Comedy();
			break;
		case 'D':
			Movie* movie2 = new Drama();
			break;
		case 'C':
			Movie* movie3 = new Classic();
			break;
		default:
			cout << "invalid input" << endl;
			break;
		}
	}

    cout << type << endl;
    cout << restOfLine << endl;

}

//SHOULD ACCEPT INFILE, FIX THAT
void Business::buildCustomers(ifstream& customerFile){
	//logic for reading file and adding stuff to the tree
}

//SHOULD ACCEPT INFILE, FIX THAT
void Business::processTransactions(ifstream& transactionsFile){
	//logic for reading file and adding stuff to the tree


}



