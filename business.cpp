/*
 * business.cpp
 *
 *  Created on: Dec 1, 2016
 *      Author: MacBook
 */

#include "business.h"

//constructor
Business::Business() {

	//creating pointers for every type of movies
	allComedies = new BinTree();
	allDramas = new BinTree();
	allClassics = new BinTree();

	//not sure about this one
//	currentTransaction = NULL;
}

//destructor
Business::~Business() {
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

void Business::buildMovies(ifstream& movFile) {

	char type = 'z';
	string restOfLine;

	while (!movFile.eof()) {
		Movie* movie = NULL;
		movFile >> type;
		getline(movFile, restOfLine);
		switch (type) {
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
			break;
		default:
			cout << "invalid movie type" << endl;
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

}

void Business::buildCustomers(ifstream& customerFile) {
	//logic for reading file and adding stuff to the tree
}

//SHOULD ACCEPT INFILE, FIX THAT
void Business::processTransactions(ifstream& transactionsFile) {
	//logic for reading file and adding stuff to the tree
	char type = 'z';
	int custID = 0;
	char mediaType = 'z';
	char movieType = 'z';
	string restOfLine;

	while (!transactionsFile.eof()) {
		Transaction* tran = NULL;
		transactionsFile >> type;
		transactionsFile >> custID;
		transactionsFile >> mediaType;
		transactionsFile >> movieType;
		getline(transactionsFile, restOfLine);

		switch (type) {
		case 'B': {

			tran = new Borrow();

			switch (movieType) {
			case 'F':
				tran->setData(*allComedies, restOfLine, movieType);
				break;
			case 'D':
				tran->setData(*allDramas, restOfLine, movieType);
				break;
			case 'C':
				tran->setData(*allClassics, restOfLine, movieType);
				break;
			default:
				cout << "INVALID MOVIE TYPE" << endl;
				break;

			}

			/*
			 *
			 * INSERT TRANSACTION POINTER INTO THE STORAGE!
			 *
			 *
			 */

			break;
		}
		case 'R':
			tran = new Return();

			switch (movieType) {
			case 'F':
				tran->setData(*allComedies, restOfLine, movieType);
				break;
			case 'D':
				tran->setData(*allDramas, restOfLine, movieType);
				break;
			case 'C':
				tran->setData(*allClassics, restOfLine, movieType);
				break;
			default:
				cout << "INVALID MOVIE TYPE" << endl;
				break;

			}

			/*
			 *
			 * INSERT TRANSACTION POINTER INTO THE STORAGE!
			 *
			 *
			 */

			break;
//		case 'I':
//			movie = new Classic();
//			movie->setData(restOfLine);
//			allClassics->insert(movie);
//
//			//classic movies are processed differently
//			//have to modify set data in Classic
//
//			break;
//		case 'H':
//			movie = new Classic();
//			movie->setData(restOfLine);
//			allClassics->insert(movie);
//
//			//classic movies are processed differently
//			//have to modify set data in Classic
//
//			break;
		default:
			cout << "invalid transaction type" << endl;
			break;
		}
	}

}

