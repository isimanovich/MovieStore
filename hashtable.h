

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <iostream>
#include "customer.h"
using namespace std;

class HashTable {
public:

	HashTable();
	~HashTable();

	bool add(int id, Customer &newCustomer);


private:
	struct Customer {
		int ID;
		Customer* aCustomer = NULL;
	};
	int size = 1001;

	Customer* array;

};



#endif /* HASHTABLE_H_ */
