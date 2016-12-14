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


void Customer::storeTransaction(Transaction* tran){

}

void Customer::getLatestTransaction() const{
	if(history.empty()){
		cout << "NO TRANSACTIONS FOR " << id << " CUSTOMER ID" << endl;
	}else{
		Transaction* tran = NULL;
		/*
		 * get transaction from stack
		 * print data
		 * put back in stack
		 *
		 */
	}
}

