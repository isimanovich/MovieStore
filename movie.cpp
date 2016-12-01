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
