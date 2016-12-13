/*
 * drama.cpp
 *
 *  Created on: Dec 1, 2016
 *      Author: MacBook
 */

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
//	cout << instock << endl;
	dataStream.ignore(256, ',');		//ignoring comma after number
	//reading director
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
//	cout << year << endl;
}

bool Drama::display()const{
	return false;
}

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

