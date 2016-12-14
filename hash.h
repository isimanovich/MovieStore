#ifndef HASH_H_
#define HASH_H_

#include <iostream>
#include "customer.h"

using namespace std;

class Hash {
public:

	Hash();
	~Hash();
	bool test(int, Customer&);

private:
	struct Cust {
		int id;
		Customer* aCustomer = NULL;
	};
	int size = 1001;
//	Cust* array;
};



#endif /* HASH_H_ */
