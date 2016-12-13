

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

class Business;
class HashTable {
public:

	HashTable();
	~HashTable();
	void insert();


private:
	struct Customer {
		int id;
		Customer* aCustomer;
	};

};



#endif /* HASHTABLE_H_ */
