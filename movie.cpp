#include "movie.h"

void Movie::borrow(){
	this->instock--;
}

void Movie::returN(){
	this->instock++;
}


bool Movie::operator<(const Movie &rhs)const{
	if(this->title < rhs.title)
		return true;
	else
		return false;
}

bool Movie::operator==(const Movie& rhs)const{
	if(this->title == rhs.title)
		return true;
	else
		return false;
}

//consider passing line and decompose inside or full file,
//but that probably should be in business
void Movie::setData(int quantity, string dirFirst, string dirLast, string title, int year){
	this->instock = quantity;
	this->dirFirstName = dirFirst;
	this->dirLastName = dirLast;
	this->title = title;
	this->year = year;
}
