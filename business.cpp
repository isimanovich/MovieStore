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
		Movie* movie = NULL;
		movFile >> type;
		getline(movFile,restOfLine);
		switch(type){
		case 'F':
			movie = new Comedy();
			movie->setData(restOfLine);
			allComedies->insert(movie);
			break;
		case 'D':
			movie = new Drama();
			movie->setData(restOfLine);
			allDramas->insert(movie);
			break;
		case 'C':
			movie = new Classic();
			movie->setData(restOfLine);
			allClassics->insert(movie);

			//classic movies are processed differently
			//have to modify set data in Classic


			break;
		default:
			cout << "invalid input" << endl;
			break;
		}
	}

	//testing what's inside of trees

	cout << "comedies: " << endl;
	cout << *allComedies << endl;
	cout << endl;
	cout << "dramas: " << endl;
	cout << *allDramas << endl;
	cout << endl;
	cout << "classics: " << endl;
	cout << *allClassics << endl;
//	allComedies->displaySideways();

}

//SHOULD ACCEPT INFILE, FIX THAT
void Business::buildCustomers(ifstream& customerFile){
	//logic for reading file and adding stuff to the tree
}

//SHOULD ACCEPT INFILE, FIX THAT
void Business::processTransactions(ifstream& transactionsFile){
	//logic for reading file and adding stuff to the tree


}



