// ------------------------------------------------- return.h -------------------------------------------------------
// Name: Ihar Simanovich & Jason Kozodoy
// Course: CSS343 A
// Creation Date: 12/01/2016
// Last Modification: 12/14/2016
// ------------------------------------------------------------------------------------------------------------------
// Purpose:
// ------------------------------------------------------------------------------------------------------------------
// Notes:
// ------------------------------------------------------------------------------------------------------------------
#ifndef RETURN_H
#define RETURN_H
#include "transaction.h"
using namespace std;

//Class Return
//Inherits from Transaction represents a
//type of transaction
class Return: public Transaction
{
public:
	Return();
	~Return();
<<<<<<< HEAD
	void setData(string, char); //sets the data for return
	void doTransaction(BinTree&, char); //does the transaction
	void display() const;
=======
	void setData(string, char);
	void doTransaction(BinTree&, char);
<<<<<<< HEAD
>>>>>>> origin/master
=======
>>>>>>> origin/master
	bool isSuccess();

};
#endif
