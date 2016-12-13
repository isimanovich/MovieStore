
#include <string>
#include <stack>
#include "transaction.h"
using namespace std;

class Customer {

public:

	Customer(string first, string last, int customerId);
	~Customer();
	int getID() const;
	void setCustomer(string firstName, string lastName, int customerId);



private:
	string firstName;
	string lastName;
	int id;
	stack<Transaction> transactionHistory;

};


