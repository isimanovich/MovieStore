#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <string>
#include <stack>
#include "transaction.h"

using namespace std;

class Customer {

public:

	Customer(string, string, int);
	~Customer();
	int getID() const;
	void setCustomer(string, string, int);
	void storeTransaction(Transaction*);
	void getLatestTransaction() const;
	void getHistory();
	void makeEmpty();

private:
	string firstName;
	string lastName;
	int id;
	stack<Transaction*> history;
//	void historyHelper();

};

#endif /* CUSTOMER_H_ */
