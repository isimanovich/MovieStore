#ifndef HISTORY_H
#define HISTORY_H

#include "transaction.h"
using namespace std;

class History : public Transaction
{  
public: 
   History();
//   History(const History&);
   ~History();
   virtual void setData(BinTree&, string);
   void display() const;
//   virtual Transaction* create();
};
#endif
