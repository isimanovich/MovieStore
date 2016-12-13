

#include <string>
using namespace std;

class Customer {

public:

	Customer(){


	}

	~Customer(){


	}

	int getID(){
		return idNumber;
	}



private:
	string lastName;
	string firstName;
	int idNumber;



};


