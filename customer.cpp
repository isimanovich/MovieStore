#include "customer.h"
using namespace std;

Customer::Customer(string first, string last, int customerId){
	firstName = first;
	lastName = last;
	id = customerId;
}

Customer::~Customer(){

}

int Customer::getID() const {
	return id;
}

void Customer::setCustomer(string first, string last, int customerId){
 firstName = first;
 lastName = last;
 id = customerId;
}







