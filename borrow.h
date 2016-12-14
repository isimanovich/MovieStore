
#ifndef BORROW_H
#define BORROW_H

#include "transaction.h"
using namespace std;

class Borrow : public Transaction
{
public:
   Borrow();
//   Borrow(const Borrow&);
   ~Borrow();
   void setData(string, char);
   void display() const;
   void doTransaction(BinTree&, char);
   bool isSuccess();
//   virtual Transaction* create();
};
#endif
