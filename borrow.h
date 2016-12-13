
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
   void setData(BinTree&, string, char);
   void display() const;
//   virtual Transaction* create();
};
#endif
