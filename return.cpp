//
//#include "return.h"
//
//
//Return::Return() :Transaction()
//{
//   transactiontype = "Return";
//}
//
//
//Return::Return(const Return& rhs)
//{
//   transactiontype = rhs.transactiontype;
//   mediaType = rhs.mediaType;
//   item = rhs.item;
//}
//
//Return::~Return()
//{}
//
//
//bool Return::setData(string media, Movie* newMovie, Customer* theCustomer)
//{
//   if(newMovie != NULL)
//   {
//      mediaType = media;
//      item = newMovie;
//
//      if (mediaType != "")
//         item->returN();
//   }
//   return true;
//}
//
//
//void Return::display() const
//{
//   cout << mediaType << " " << transactiontype << " ";
//}
//
//Transaction* Return::create()
//{
//   return new Return(); //create return obj
//}
