/*
 * classic.cpp
 *
 *  Created on: Dec 1, 2016
 *      Author: MacBook
 */

#include "classic.h"
#include <sstream>

using namespace std;

Classic::Classic(){
	month = 0;
}

Classic::~Classic(){

}

void Classic::setData(string data){

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
//	this->data = title;			//setting data to title name, so node can be stored in the tree
	//getting a year of the movie


	//WHAT IF ACTOR NAME IS OUT OF 3 WORDS??????????????????????????????????


	string actorFirst,actorLast;
	dataStream >> actorFirst;
	dataStream >> actorLast;
	actor = actorFirst + " " + actorLast;
	dataStream >> month;
	dataStream >> year;
//	cout << year << endl;



}

bool Classic::display()const{
	return false;
}

bool Classic::operator<(const Classic &rhs) const {
	if (this->year < rhs.year)
		return true;
	else if (this->year == rhs.year && this->month < rhs.month)
		return true;
	else if (this->year == rhs.year && this->month == rhs.month
			&& actor < rhs.actor) {
		return true;
	} else
		return false;
}

bool Classic::operator>(const Classic &rhs) const {
	if (this->year > rhs.year)
		return true;
	else if (this->year == rhs.year && this->month > rhs.month)
		return true;
	else if (this->year == rhs.year && this->month == rhs.month
			&& actor > rhs.actor) {
		return true;
	} else
		return false;
}

bool Classic::operator==(const Classic& rhs) const {
	if (this->month == rhs.month && this->year == rhs.year
			&& this->actor == rhs.actor)
		return true;
	else
		return false;
}


