#include "customer.h"

//constructor inializes the customer data members
Customer::Customer(string first, string last, int customerId) {
	firstName = first;
	lastName = last;
	id = customerId;
}

//destrucotr calls make empty
Customer::~Customer() {

//	while (!history.empty()) {
//		Transaction* del = history.top();
//		history.pop();
//		delete del;
//	}
	this->makeEmpty();
}

//returns the id
int Customer::getID() const {
	return id;
}

//deletes the transaction history
void Customer::makeEmpty() {
	while (!history.empty()) {
		Transaction* del = history.top();
		history.pop();
		delete del;
	}
}

//sets the data members of a customer
void Customer::setCustomer(string first, string last, int customerId) {
	firstName = first;
	lastName = last;
	id = customerId;
}

//stores a transaction pointer in the history stack
void Customer::storeTransaction(Transaction* tran) {
	history.push(tran);

}

//gets a customers latest transaction
void Customer::getLatestTransaction() const {
	if (history.empty()) {
		cout << "NO TRANSACTIONS FOR " << id << " CUSTOMER ID" << endl;
	} else {
		/*
		 * get transaction from stack
		 * print data
		 * put back in stack
		 *
		 */
		Transaction* tran = NULL;
		tran = history.top();
		cout << "Latest transaction for " << id << " customer ID" << endl;
		cout << "Movie: " << tran->getTitle() << " " << tran->getYear()
				<< "; Transaction type: " << tran->getTransType() << endl;

	}
}

//gets a customers history
void Customer::getHistory() {
	if (history.empty()) {
//		cout << "NO TRANSACTIONS FOR " << id << " CUSTOMER ID" << endl;
	} else {
		/*
		 * get transaction from stack
		 * print data
		 * put back in stack
		 *
		 */
		Transaction* tran = NULL;
		tran = history.top();
		history.pop();
//		cout << "Latest transaction for " << id << " customer ID" << endl;
		cout << "Movie: " << tran->getTitle() << " " << tran->getYear()
				<< "; Transaction type: " << tran->getTransType() << endl;
		getHistory();
		history.push(tran);

		tran = NULL;
		delete tran;

	}
}

