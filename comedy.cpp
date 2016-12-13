/*
 * comedy.cpp
 *
 *  Created on: Dec 1, 2016
 *      Author: MacBook
 */

#include "comedy.h"
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

Comedy::Comedy(){

}

Comedy::~Comedy(){

}

bool Comedy::display()const{
	cout << this->title << endl;
	return false;
}

void Comedy::setData(string data){

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

	//getting a year of the Comedy
	dataStream >> year;
//	cout << year << endl;
}

bool Comedy::operator<(const Comedy &rhs) const {
	if (this->title < rhs.title)
		return true;
	else if(this->title == rhs.title && this->year < rhs.year)
		return true;
	else
		return false;
}

bool Comedy::operator>(const Comedy &rhs) const {

	if(this->title > rhs.title)
		return true;
	else if(this->title == rhs.title && this->year > rhs.year)
			return true;
	else
		return false;
}

bool Comedy::operator==(const Comedy& rhs) const {
	if (this->title == rhs.title && this->year == rhs.year)
		return true;
	else
		return false;
}
