

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <iostream>
using namespace std;
class Business;
class HashTable {
public:

	HashTable();
	~HashTable();
	void insert();


private:
	struct Customer {
		int id;
		Customer* aCustomer = NULL;
	};
	int size = 1001;

	Customer* array;

};



#endif /* HASHTABLE_H_ */
