
#include "return.h"


Return::Return() :Transaction()
{
   transactiontype = "Return";
}


Return::Return(const Return& rhs)
{
   transactiontype = rhs.transactiontype;
   mediaType = rhs.mediaType;
   item = rhs.item;
}

Return::~Return()
{}


bool Return::setData(string media, Media* newMovie,
   Customer* theCustomer)
{
   if(newMovie != NULL)
   {
      mediaType = media;
      item = newMovie;

      if (mediaType != "")
         item->increaseCopies();
   }
   return true;
}


void Return::display() const
{
   cout << mediaType << " " << transactiontype << " ";
}

Transaction* Return::doTransaction()
{
   return new Return();
}
