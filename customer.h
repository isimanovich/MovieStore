// -------------------------------------------------- customer.h ----------------------------------------------------
// Name: Ihar Simanovich & Jason Kozodoy
// Course: CSS343 A
// Creation Date: 12/01/2016
// Last Modification: 12/14/2016
// ------------------------------------------------------------------------------------------------------------------
#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <string>
#include <stack>
#include "transaction.h"

using namespace std;

//Represents a customer
class Customer {

public:

	Customer(string, string, int);
	~Customer();
	int getID() const; //gets id from current customer
	void setCustomer(string, string, int); //sets a new customer
	void storeTransaction(Transaction*); //stores trasaction
	void getLatestTransaction() const; //gets the latest transaction
	void getHistory(); //gets the history of the customer
	void makeEmpty();

private:
	string firstName;
	string lastName;
	int id;
	stack<Transaction*> history;
//	void historyHelper();

};

#endif /* CUSTOMER_H_ */
