#include "customer.h"

Customer::Customer(string first, string last, int customerId) {
	firstName = first;
	lastName = last;
	id = customerId;
}

Customer::~Customer() {

}

int Customer::getID() const {
	return id;
}

void Customer::setCustomer(string first, string last, int customerId) {
	firstName = first;
	lastName = last;
	id = customerId;
}

void Customer::storeTransaction(Transaction* tran) {
	history.push(tran);

}

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

		//maybe not needed
		tran = NULL;
		delete tran;

	}
}

