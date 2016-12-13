#include "movie.h"
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

//default constructor
//setting private data members to its default values
Movie::Movie() {
	borrowedCount = 0;
	director = "";
	instock = 0;
	media = "DVD";
	title = "";
	year = 0;
}

Movie::~Movie(){

}

//still need destructor

void Movie::borrow() {
	this->instock--;
}

void Movie::returN() {
	this->instock++;
}

bool Movie::operator<(const Movie &rhs) const {
	if (this->title < rhs.title)
		return true;
	else
		return false;
}

bool Movie::operator>(const Movie &rhs) const {

	if(this->title > rhs.title)
		return true;
	else
		return false;
}



bool Movie::operator==(const Movie& rhs) const {
	if (this->title == rhs.title)
		return true;
	else
		return false;
}

//consider passing line and decompose inside or full file,
//but that probably should be in business
void Movie::setData(string data) {

	string dirFirstName, dirLastName;
	istringstream dataStream(data);		//opening stream
	dataStream.ignore(256, ' ');		//ignoring first comma
	dataStream >> instock;				//getting quantity in stock
//	cout << instock << endl;
	dataStream.ignore(256, ',');		//ignoring comma after number
	//reading director
	string temp;
	dataStream >> temp;

	for (;;) {
			//no comma case, adding words to title
			if (temp.find(',') == -1) {
				director += temp;
				director += " ";
				dataStream >> temp;
			}

			//comma case, removing comma and adding to title then break
			else {

				temp = temp.substr(0, temp.size() - 1);
				director += temp;
				break;

			}
		}

	//reading title
	dataStream >> temp;
	for (;;) {
		//no comma case, adding words to title
		if (temp.find(',') == -1) {
			title += temp;
			title += " ";
			dataStream >> temp;
		}

		//comma case, removing comma and adding to title then break
		else {

			temp = temp.substr(0, temp.size() - 1);
			title += temp;
			break;

		}
	}
//	this->data = title;		//setting data to title name, so node can be stored in the tree
	//getting a year of the movie
	dataStream >> year;
//	cout << year << endl;
}


void Movie::increaseStock(int value){
	instock += value;
}


bool Movie::display()const{
	cout << this->title << endl;
	return false;
}

string Movie::getTitle(){
	return title;
}

int Movie::getYear(){
	return year;
}

string Movie::getDirector(){
	return director;
}

int Movie::getAmountIn(){
	return instock;
}
