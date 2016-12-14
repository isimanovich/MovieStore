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

	allCustomers->makeEmpty();
	delete allCustomers;
}

void Business::buildMovies(ifstream& movFile) {

	char type = 'z';
	string restOfLine;
	movFile >> type;
	while (!movFile.eof()) {
		Movie* movie = NULL;

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
			cout << "Invalid Movie Type: " << type  << endl;
			break;
		}
		movFile >> type;
	}
}

void Business::buildCustomers(ifstream& customerFile) {
	//logic for reading file and adding stuff to the tree
	int ID;
	string first;
	string last;
	string temp;
	customerFile >> ID;
	while (!customerFile.eof()) {
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
		customerFile >> ID;
	}
}

void Business::processTransactions(ifstream& transactionsFile) {
	//logic for reading file and adding stuff to the tree
	char type = 'z';
	int custID = 0;
	char mediaType = 'z';
	char movieType = 'z';
	string restOfLine, toGetNewLine;
	transactionsFile >> type;
	while (!transactionsFile.eof()) {
		Transaction* tran = NULL;

		switch (type) {
		case 'B': {
			transactionsFile >> custID;
			transactionsFile >> mediaType;
			transactionsFile >> movieType;
			getline(transactionsFile, restOfLine);
			Customer* cust = allCustomers->find(custID);
			if (cust == NULL)
				break;

			/*
			 *
			 *
			 * VERIFY CUSTOME ID BEFORE DOING TRANSACTIONS
			 */

			switch (movieType) {
			case 'F':
				tran = new Borrow();
				tran->setData(restOfLine, movieType);
				tran->doTransaction(*allComedies, movieType);
				break;
			case 'D':
				tran = new Borrow();
				tran->setData(restOfLine, movieType);
				tran->doTransaction(*allDramas, movieType);
				break;
			case 'C':
				tran = new Borrow();
				tran->setData(restOfLine, movieType);
				tran->doTransaction(*allClassics, movieType);
				break;
			default:
//				delete tran;
				cout << movieType << " - INVALID MOVIE GENRE, CAN'T BORROW"
						<< endl;
				break;

			}

			if (tran == NULL)
				break;
			if (!tran->isSuccess()) {
				delete tran;
				break;
			}
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
			Customer* cust = allCustomers->find(custID);
			if (cust == NULL)
				break;

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
				tran = new Return();
				tran->setData(restOfLine, movieType);
				tran->doTransaction(*allComedies, movieType);
				break;
			case 'D':
				tran = new Return();
				tran->setData(restOfLine, movieType);
				tran->doTransaction(*allDramas, movieType);
				break;
			case 'C':
				tran = new Return();
				tran->setData(restOfLine, movieType);
				tran->doTransaction(*allClassics, movieType);
				break;
			default:
				cout << movieType << " - INVALID MOVIE GENRE, CAN'T RETURN"
						<< endl;
				break;

			}

			if (tran == NULL)
				break;
			if (!tran->isSuccess()) {
				delete tran;
				break;
			}

			//store transaction in the STACK of CUSTOMER by ID

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
			cout << endl;
			cout << "INVENTORY OF THE STORE: " << endl;
			allComedies->printData();
			cout << endl;
			allDramas->printData();
			cout << endl;
			allClassics->printData();
			cout << endl;
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
		transactionsFile >> type;
	}

}

