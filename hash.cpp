#include "hash.h"

//default constructor initializes the array
Hash::Hash() {
	initArray(size);
}

//deletes the customerList by calling makeEmpty function
Hash::~Hash() {
	this->makeEmpty();
	delete [] customerList;
}

//create customerlist array and initilize id's and customer
//to default values.
void Hash::initArray(int size) {
	customerList = new Cust[size];
	for (int i = 0; i < size; i++) {
		customerList[i].id = 0;
		customerList[i].aCustomer = NULL;
	}
}

//makes the hashtable empty. Deletes the customer objects
//stored in the hashtable sets ids back to zero
void Hash::makeEmpty() {
	for (int i = 0; i < size; i++) {
		customerList[i].id = 0;
		if (customerList[i].aCustomer != NULL){
			customerList[i].aCustomer->makeEmpty();
			delete customerList[i].aCustomer;
			customerList[i].aCustomer = NULL;
		}
	}
}

//adds a new customer to the hashtable
//hashtable holds customer objects with ids
void Hash::add(int id, Customer* newCustomer) {
	int hash = id % size;

	if (customerList[hash].id == 0) {
		customerList[hash].id = newCustomer->getID();
		customerList[hash].aCustomer = newCustomer;
	} else {
		while (customerList[hash].id != 0) {
			hash = (hash + 1) % size;
			customerList[hash].id = newCustomer->getID();
			customerList[hash].aCustomer = newCustomer;
		}
	}
}

//finds a customer in hashtable given an id
Customer* Hash::find(int key) {
	int index = key % size;
	//match found, return customer
	if (customerList[index].id == key)
		return customerList[index].aCustomer;

	//no match, keep hashing until found, or no more possibilities to find
	else {
		while (customerList[index].id != key) {
			index = (index + 1) % size;
			if (customerList[index].id == key)
				return customerList[index].aCustomer;
			if (customerList[index].id == 0)
				break;
		}
		return NULL;
	}
}

