#ifndef HASH_H_
#define HASH_H_

#include <iostream>
#include "customer.h"

using namespace std;

class Hash {
public:

	Hash();
	~Hash();
	void add(int, Customer*);
	void initArray(int);
	Customer& find(int key);

private:
	struct Cust {
		int id;
		Customer* aCustomer = NULL;
	};
	int size = 1001;
	Cust* customerList = NULL;

};

#endif /* HASH_H_ */
