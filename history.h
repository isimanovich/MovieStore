

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
   virtual void setData(string);
//   virtual Transaction* create();
};
#endif
