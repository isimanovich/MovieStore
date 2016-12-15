// --------------------------------------------------- hash.h -------------------------------------------------------
// Name: Ihar Simanovich & Jason Kozodoy
// Course: CSS343 A
// Creation Date: 12/01/2016
// Last Modification: 12/14/2016
// ------------------------------------------------------------------------------------------------------------------
#ifndef HASH_H_
#define HASH_H_

#include <iostream>
#include "customer.h"

using namespace std;

//Hash class that repersents a hash table
class Hash {
public:
	Hash();
	~Hash();
	void add(int, Customer*); //adds customer to hashtable
	void initArray(int); //initalizes array to default
	Customer* find(int key); //finds customer based on id
	void makeEmpty(); //deletes hashtable

private:
	struct Cust {
		int id;
		Customer* aCustomer = NULL;
	};
	int size = 1001;
	Cust* customerList = NULL;
};

#endif /* HASH_H_ */
