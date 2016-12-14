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

	//possibly won't be able to keep CONST
	//cuz will have to pop() recursively
	bool getHistory() const;

private:
	string firstName;
	string lastName;
	int id;
	stack<Transaction> history;

};

