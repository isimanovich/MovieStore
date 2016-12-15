// -------------------------------------------------- drama.cpp -----------------------------------------------------
// Name: Ihar Simanovich & Jason Kozodoy
// Course: CSS343 A
// Creation Date: 12/01/2016
// Last Modification: 12/14/2016
// ------------------------------------------------------------------------------------------------------------------
#include <sstream>
#include <iostream>
#include <string>
#include "drama.h"

using namespace std;

Drama::Drama(){

}


Drama::Drama(string director, string title){
	this->director = director;
	this->title = title;
}

Drama::~Drama(){

}

void Drama::setData(string data){

	istringstream dataStream(data);		//opening stream
	dataStream.ignore(256, ' ');		//ignoring first comma
	dataStream >> instock;				//getting quantity in stock
	dataStream.ignore(256, ',');		//ignoring comma after number
	string temp;
	dataStream >> temp;

	//reading director
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

void Drama::display()const{

	cout << "D, Stock: " << instock << ", Borrowed: "<< borrowedCount
			 << ", " << director << ", "  << title << ", " <<  year <<  endl;

}

//ASSUMPTION: since director is a variable to store both first and last
//			  names, when sorting drama movies by director, it sorts
//			  primarily by first name
bool Drama::operator<(const Movie &rhs) const {

	const Drama& rhS = static_cast<const Drama&>(rhs);

	if (director < rhS.director)
		return true;
	else if (director == rhS.director && title < rhS.title)
		return true;
	else
		return false;
}

bool Drama::operator<(const Drama &rhs) const {
	if (director < rhs.director)
		return true;
	else if (director == rhs.director && title < rhs.title)
		return true;
	else
		return false;
}


bool Drama::operator==(const Movie& rhs) const {

	const Drama& rhS = static_cast<const Drama&>(rhs);
	if(director == rhS.director && title == rhS.title)
		return true;
	else
		return false;
}

bool Drama::operator==(const Drama& rhs) const {

	if (director == rhs.director && title == rhs.title)
		return true;
	else
		return false;
}
