// ------------------------------------------------- return.h -------------------------------------------------------
// Name: Ihar Simanovich & Jason Kozodoy
// Course: CSS343 A
// Creation Date: 12/01/2016
// Last Modification: 12/14/2016
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

	void setData(string, char);//sets the data for return
	void doTransaction(BinTree&, char);//does the transaction
	bool isSuccess();

};
#endif
