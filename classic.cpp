/*
 * classic.cpp
 *
 *  Created on: Dec 1, 2016
 *      Author: MacBook
 */

#include "classic.h"
#include <sstream>

using namespace std;

Classic::Classic() {
	month = 0;
	actor = "";
}

Classic::Classic(int month, int year, string actor) {
	this->actor = actor;
	this->month = month;
	this->year = year;
}

Classic::~Classic() {

}

void Classic::setData(string data) {

//	cout << "this is what i get for classic: " << endl;
//	cout << data << endl;

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

	//WHAT IF ACTOR NAME IS OUT OF 3 WORDS??????????????????????????????????

	string actorFirst, actorLast;
	dataStream >> actorFirst;
	dataStream >> actorLast;
	actor = actorFirst + " " + actorLast;
	dataStream >> month;
	dataStream >> year;

}

void Classic::display() const {

	cout << "C, Stock: " << instock << ", Borrowed: "<< borrowedCount
			<< ", " << director << ", "  << title << ", " << actor
			<< ", " << month << " " <<  year <<  endl;

}

bool Classic::operator<(const Movie &rhs) const {

	const Classic& rhS = static_cast<const Classic&>(rhs);

	if (year < rhS.year)
		return true;
	else if (year == rhS.year && month < rhS.month)
		return true;
	else if (year == rhS.year && month == rhS.month && actor < rhS.actor) {
		return true;
	} else
		return false;
}

bool Classic::operator<(const Classic &rhs) const {
	if (year < rhs.year)
		return true;
	else if (year == rhs.year && month < rhs.month)
		return true;
	else if (year == rhs.year && month == rhs.month && actor < rhs.actor) {
		return true;
	} else
		return false;
}

bool Classic::operator==(const Movie& rhs) const {
	const Classic& rhS = static_cast<const Classic&>(rhs);

	if (month == rhS.month && year == rhS.year){
		if(actor == rhS.actor)
			return true;
		else if (title == rhS.title)
			return true;
	}
	return false;
}

bool Classic::operator==(const Classic& rhs) const {
	if (month == rhs.month && year == rhs.year){
			if(actor == rhs.actor)
				return true;
			else if (title == rhs.title)
				return true;
		}
		return false;
}

