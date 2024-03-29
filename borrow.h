// ------------------------------------------------- borrow.h -------------------------------------------------------
// Name: Ihar Simanovich & Jason Kozodoy
// Course: CSS343 A
// Creation Date: 12/01/2016
// Last Modification: 12/14/2016
// ------------------------------------------------------------------------------------------------------------------
#ifndef BORROW_H
#define BORROW_H

#include "transaction.h"
using namespace std;

//Borrow represensts a type of Transaction
class Borrow : public Transaction
{
public:
   Borrow();
   ~Borrow();
   void setData(string, char);
   void doTransaction(BinTree&, char); //do transaction
   bool isSuccess(); //borrow is successful
};
#endif
