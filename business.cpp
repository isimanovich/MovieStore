/*
 * business.cpp
 *
 *  Created on: Dec 1, 2016
 *      Author: MacBook
 */

#include "business.h"
#include <string.h>

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
	string restOfLine, getNewLine;

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
//
//	cout << "comedies: " << endl;
//	cout << *allComedies << endl;
//	cout << endl;
//	cout << "dramas: " << endl;
//	cout << *allDramas << endl;
//	cout << endl;
//	cout << "classics: " << endl;
//	cout << *allClassics << endl;

}

void Business::buildCustomers(ifstream& customerFile) {
	//logic for reading file and adding stuff to the tree
	int customerId;
	string fullName;
	string firstName;
	string lastName;
	string temp;

	while (!customerFile.eof()) {
		customerFile >> customerId;

		customerFile >> firstName;
		customerFile >> lastName;
		getline(customerFile, temp);
		cout << customerId << endl;
		cout << firstName << " ";
		cout << lastName << endl;
		Customer* customer = NULL;

		/*
		 *  - create new customer object
		 *  - store it in hashtable
		 */

	}
}

//SHOULD ACCEPT INFILE, FIX THAT
void Business::processTransactions(ifstream& transactionsFile) {
	//logic for reading file and adding stuff to the tree
	char type = 'z';
	int custID = 0;
	char mediaType = 'z';
	char movieType = 'z';
	string restOfLine, toGetNewLine;

	while (!transactionsFile.eof()) {
		Transaction* tran = NULL;
		transactionsFile >> type;

		switch (type) {
		case 'B': {
			transactionsFile >> custID;
			transactionsFile >> mediaType;
			transactionsFile >> movieType;
			getline(transactionsFile, restOfLine);

			tran = new Borrow();

			switch (movieType) {
			case 'F':
				tran->setData(restOfLine, movieType);
				tran->doTransaction(*allComedies, movieType);
				break;
			case 'D':
				tran->setData(restOfLine, movieType);
				tran->doTransaction(*allDramas, movieType);
				break;
			case 'C':
				tran->setData(restOfLine, movieType);
				tran->doTransaction(*allClassics, movieType);
				break;
			default:
				cout << "INVALID MOVIE GENRE, CAN'T BORROW" << endl;
				break;

			}


			//store transaction in the STACK of CUSTOMER by ID

			/*
			 *
			 * INSERT TRANSACTION POINTER INTO THE STORAGE!
			 *
			 *
			 */

			break;
		}
		case 'R': {
			transactionsFile >> custID;
			transactionsFile >> mediaType;
			transactionsFile >> movieType;
			getline(transactionsFile, restOfLine);

			tran = new Return();


			/*
			 * NEED TO CHECK IF CUSTOMER BORROWED THIS MOVIE,
			 * IF NOT HE CAN"T RETURN IT!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			 *
			 *
			 * - create new transaction object
			 * - search for it in customer
			 *
			 */

			switch (movieType) {
			case 'F':
				tran->setData(restOfLine, movieType);
				tran->doTransaction(*allComedies, movieType);
				break;
			case 'D':
				tran->setData(restOfLine, movieType);
				tran->doTransaction(*allDramas, movieType);
				break;
			case 'C':
				tran->setData(restOfLine, movieType);
				tran->doTransaction(*allClassics, movieType);
				break;
			default:
				cout << "INVALID MOVIE GENRE, CAN'T RETURN" << endl;
				break;

			}

			//store transaction in the STACK of CUSTOMER by ID

			/*
			 *
			 * INSERT TRANSACTION POINTER INTO THE STORAGE!
			 *
			 *
			 */

			break;
		}
		case 'I': {
			getline(transactionsFile, toGetNewLine);
			cout << "INVENTORY OF THE STORE: " << endl;
			allComedies->printData();
			cout << endl;
			allDramas->printData();
			cout << endl;
			allClassics->printData();
			break;
		}
		case 'H': {
			/*
			 * 1. read ID
			 * 2. go to HashTable and find customer
			 * 3. customer->printHisotry();
			 */
			transactionsFile >> custID;
//			getline(transactionsFile, toGetNewLine);
			cout << "HISTORY OF CUSTOMER: " << custID << endl;
			break;
		}
		default:
			cout << "ERROR: INVALID TRANSACTION TYPE" << endl;
			break;
		}

	}

}

