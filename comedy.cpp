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

Comedy::Comedy(string title, int year){
	this->title = title;
	this->year = year;
}

Comedy::~Comedy(){

}

void Comedy::display()const{

	cout << "F, Stock: " << instock << ", Borrowed: "<< borrowedCount
		 << ", " << director << ", "  << title << ", " <<  year <<  endl;

}

void Comedy::setData(string data){

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

	//getting a year of the Comedy
	dataStream >> year;
//	cout << year << endl;
}

bool Comedy::operator<(const Movie &rhs) const {
	const Comedy& rhS = static_cast<const Comedy&>(rhs);

	if (title < rhS.title)
		return true;
	else if(title == rhS.title && year < rhS.year)
		return true;
	else
		return false;
}

bool Comedy::operator<(const Comedy &rhs) const {
	if (title < rhs.title)
		return true;
	else if(title == rhs.title && year < rhs.year)
		return true;
	else
		return false;
}


bool Comedy::operator==(const Movie& rhs) const {
	const Comedy& rhS = static_cast<const Comedy&>(rhs);
	if (title == rhS.title && year == rhS.year)
		return true;
	else
		return false;
}

bool Comedy::operator==(const Comedy& rhs) const {
	if (title == rhs.title && year == rhs.year)
		return true;
	else
		return false;
}
