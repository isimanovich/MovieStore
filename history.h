

#ifndef HISTORY_H
#define HISTORY_H
#include <iostream>

#include "movie.h"
#include "transaction.h"
using namespace std;

class Customer;
class History : public Transaction
{  
public: 
   History();
   History(const History&);
   ~History();
   virtual bool setData(string, Movie*, Customer*);
   virtual Transaction* create();
};
#endif
