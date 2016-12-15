// -------------------------------------------------- movie.cpp -----------------------------------------------------
// Name: Ihar Simanovich & Jason Kozodoy
// Course: CSS343 A
// Creation Date: 12/01/2016
// Last Modification: 12/14/2016
// ------------------------------------------------------------------------------------------------------------------
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

//default destructor
Movie::~Movie() {

}

//decrements stock and increments borrowedCount
//when a movie is borrowed
bool Movie::borrow() {
	if (instock > 0) {
		instock--;
		borrowedCount++;
		return true;
	} else {
		return false;
	}

}

//a movie is returned
void Movie::returN() {
	instock++;
	borrowedCount--;
}

//compares movies based on titles
//returns true if current object title is less
bool Movie::operator<(const Movie &rhs) const {
	if (this->title < rhs.title)
		return true;
	else
		return false;
}

//checks to see if two movies are equal by titles
bool Movie::operator==(const Movie& rhs) const {
	if (this->title == rhs.title)
		return true;
	else
		return false;
}

//sets the data for a movie
void Movie::setData(string data) {

	string dirFirstName, dirLastName;
	istringstream dataStream(data);		//opening stream
	dataStream.ignore(256, ' ');		//ignoring first comma
	dataStream >> instock;				//getting quantity in stock
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
	//getting a year of the movie
	dataStream >> year;
}

//increment the stock
void Movie::increaseStock(int value) {
	instock += value;
}

//display the info of the movie
void Movie::display() const {

}

//returns the title
string Movie::getTitle() {
	return title;
}

//returns the year
int Movie::getYear() {
	return year;
}

//returns the director
string Movie::getDirector() {
	return director;
}

//returns the amount in stock
int Movie::getAmountIn() {
	return instock;
}
