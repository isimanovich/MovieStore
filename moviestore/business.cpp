// ----------------------------------------------- business.cpp ------------------------------------------------------
// Name: Ihar Simanovich & Jason Kozodoy
// Course: CSS343 A
// Creation Date: 12/01/2016
// Last Modification: 12/14/2016
// ------------------------------------------------------------------------------------------------------------------

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
}

//destructor
Business::~Business() {
	allComedies->makeEmpty();	//making tree empty
	delete allComedies;			//deleting pointer
	allDramas->makeEmpty();		//making tree empty
	delete allDramas;			//deleting pointer
	allClassics->makeEmpty();	//making tree empty
	delete allClassics;			//deleting pointer
	allCustomers->makeEmpty();
	delete allCustomers;
}

//builds our movies by reading data about movies
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
			cout << "Invalid Movie Type: " << type << endl;
			break;
		}
		movFile >> type;
	}
}

//build our customers by reading id and names
void Business::buildCustomers(ifstream& customerFile) {
	//logic for reading file and adding stuff to the tree
	int ID;
	string first;
	string last;
	string temp;
	customerFile >> ID;
	while (!customerFile.eof()) {
		//reading data from file
		customerFile >> first;
		customerFile >> last;
		getline(customerFile, temp);

		//create new customer object
		//store it in hashtable
		Customer* customer = new Customer(first, last, ID);
		allCustomers->add(ID, customer);
		customerFile >> ID;
	}
}

//process transactions from file
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
			//searching for customer in HashTable
			Customer* cust = allCustomers->find(custID);
			//can't perform transaction if customer not found
			if (cust == NULL)
				break;

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
				cout << movieType << " - Invalid Movie Type, Can't Borrow"
						<< endl;
				cout << endl;
				break;
			}
			//if movie type is invalid transaction
			//can't be stored, so break
			if (tran == NULL)
				break;
			//if was unable to perform transaction
			//it can't be stored, so break
			if (!tran->isSuccess()) {
				delete tran;
				break;
			}
			//store transaction in the STACK of CUSTOMER by ID
			cust->storeTransaction(tran);
			break;
		}
		case 'R': {
			transactionsFile >> custID;
			transactionsFile >> mediaType;
			transactionsFile >> movieType;
			getline(transactionsFile, restOfLine);
			//searching for customer in HashTable
			Customer* cust = allCustomers->find(custID);
			//can't perform transaction if customer not found
			if (cust == NULL)
				break;

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
				cout << movieType << " - Invalid Movie Type, Can't Return"
						<< endl;
				cout << endl;
				break;

			}
			//if movie type is invalid transaction
			//can't be stored, so break
			if (tran == NULL)
				break;
			//if was unable to perform transaction
			//it can't be stored, so break
			if (!tran->isSuccess()) {
				delete tran;
				break;
			}
			//store transaction in the STACK of CUSTOMER by ID
			cust->storeTransaction(tran);
			break;
		}
		case 'I': {
			//displaying inventory of the store in sorted order
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
			//read customer ID
			//search for customer in HashTable
			//outputting history, if customer found
			//error message if customer not found
			transactionsFile >> custID;
			cout << "HISTORY OF CUSTOMER: " << custID << endl;
			Customer* cust = allCustomers->find(custID);
			if (cust != NULL) {
				cust->getHistory();
			} else {
				cerr << "Can't Show History, Customer " << custID
						<< " Is Not Found" << endl;
			}
			cout << endl;
			break;
		}
		default:
			//case for invalid input of Transaction type
			getline(transactionsFile, restOfLine);
			cout << "Invalid Transaction Type: " << type << endl;
			cout << endl;
			break;
		}
		transactionsFile >> type;
	}
}
