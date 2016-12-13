
#include <string>
#include <queue>
#include "transaction.h"
using namespace std;

class Customer {

public:

	Customer();
	~Customer();
	int getID() const;
	void setCustomer(string firstName, string lastName);



private:
	string firstName;
	string lastName;
	int id;
	queue<Transaction> transactionHistory;

};


