

#ifndef HISTORY_H
#define HISTORY_H
#include <iostream>

#include "media.h"
#include "transaction.h"
using namespace std;

class Customer;
class History : public Transaction
{  
public: 
   History();
   History(const History&);
   virtual ~History();
   virtual bool setData(string, Media*, Customer*);
   virtual Transaction* doTransaction();
};
#endif
