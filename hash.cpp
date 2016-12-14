#include "hash.h"

Hash::Hash() {
	initArray(size);

}

Hash::~Hash() {

	//should delete customerList to avoid memory leak

}

void Hash::initArray(int size) {
	customerList = new Cust[size];
	for (int i = 0; i < size; i++) {
		customerList[i].id = 0;
	}
}

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

Customer& Hash::find(int key) {
	int index = key % size;
	//match found, return customer
	if (customerList[index].id == key)
		return customerList[index].aCustomer;

	//no match, keep hashing until found, or no more possibilities to find
	else {
		while (customerList[index].id != key || customerList[index].id != 0) {
			index = (index + 1) % size;
			if (customerList[index].id == key) {
				return customerList[index].aCustomer;
			}
		}
		return NULL;
	}

}

