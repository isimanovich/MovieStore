
#ifndef BORROW_H
#define BORROW_H
#include <iostream>

#include "movie.h"
#include "transaction.h"
using namespace std;
class Customer;
class Borrow : public Transaction
{
public:
   Borrow();
   Borrow(const Borrow&);
   ~Borrow();
   virtual bool setData(string, Movie*, Customer*);
   virtual void display() const;
   virtual Transaction* create();
};
#endif
