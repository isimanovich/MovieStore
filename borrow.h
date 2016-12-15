// ------------------------------------------------- borrow.h -------------------------------------------------------
// Name: Ihar Simanovich & Jason Kozodoy
// Course: CSS343 A
// Creation Date: 12/01/2016
// Last Modification: 12/14/2016
// ------------------------------------------------------------------------------------------------------------------
// Purpose:
// ------------------------------------------------------------------------------------------------------------------
// Notes:
// ------------------------------------------------------------------------------------------------------------------
#ifndef BORROW_H
#define BORROW_H

#include "transaction.h"
using namespace std;

class Borrow : public Transaction
{
public:
   Borrow();
   ~Borrow();
   void setData(string, char);
   void doTransaction(BinTree&, char);
   bool isSuccess();
};
#endif
