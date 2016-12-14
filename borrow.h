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
