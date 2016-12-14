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

	//storage for customers
	allCustomers = new Hash();

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

	/*
	 *
	 * NEED TO DELETE HASHTABLE
	 *
	 */

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
}

void Business::buildCustomers(ifstream& customerFile) {
	//logic for reading file and adding stuff to the tree
	int ID;
	string first;
	string last;
	string temp;

	while (!customerFile.eof()) {
		customerFile >> ID;

		customerFile >> first;
		customerFile >> last;
		getline(customerFile, temp);

		/*
		 *  - create new customer object
		 *  - store it in hashtable
		 */
		Customer* customer = new Customer(first, last, ID);
		allCustomers->add(ID, customer);

		/*
		 * MIGHT NEED TO CHECK FOR BLANK LINE AT THE END OF THE FILE
		 *
		 */

	}
}

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
			Customer* cust = allCustomers->find(custID);
			if(cust == NULL)
				break;

			/*
			 *
			 *
			 * VERIFY CUSTOME ID BEFORE DOING TRANSACTIONS
			 */

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
				cout << movieType << " - INVALID MOVIE GENRE, CAN'T BORROW" << endl;
				break;

			}

			if(tran == NULL)
				break;
			//store transaction in the STACK of CUSTOMER by ID



			if (cust != NULL) {
				cust->storeTransaction(tran);
//				cerr << "BORROW SUCCESS!!!" << endl;
			} else {
				cerr << "CAN'T STORE BORROW TRAN CUST NOT FOUND!!!" << endl;
			}
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
				cout << movieType << " - INVALID MOVIE GENRE, CAN'T RETURN" << endl;
				break;

			}

			//store transaction in the STACK of CUSTOMER by ID

			Customer* cust = allCustomers->find(custID);

			if (cust != NULL) {
				cust->storeTransaction(tran);
//				cerr << "RETURN SUCCESS!!!" << endl;
			} else {
				cerr << "CAN'T STORE RETURN TRAN CUST NOT FOUND!!!" << endl;
			}

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
			 *
			 *
			 *
			 *
			 * 2. go to HashTable and find customer
			 *
			 *
			 *
			 *
			 * 3. customer->printHisotry();
			 */
			transactionsFile >> custID;
			cout << "HISTORY OF CUSTOMER: " << custID << endl;
			Customer* cust = allCustomers->find(custID);

			if (cust != NULL) {
				cust->getHistory();
			} else {
				cerr << "CAN'T SHOW HISTORY, CUST NOT FOUND!!!" << endl;
			}
//			getline(transactionsFile, toGetNewLine);
			break;
		}
		default:
			getline(transactionsFile, restOfLine);
			cout << "ERROR: INVALID TRANSACTION TYPE" << endl;
			break;
		}

	}

}

