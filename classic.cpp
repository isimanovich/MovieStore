// ------------------------------------------------ classic.cpp -----------------------------------------------------
// Name: Ihar Simanovich & Jason Kozodoy
// Course: CSS343 A
// Creation Date: 12/01/2016
// Last Modification: 12/14/2016
// ------------------------------------------------------------------------------------------------------------------
#include "classic.h"
#include <sstream>

using namespace std;

//default construtor sets month and actor to default values
Classic::Classic() {
	month = 0;
	actor = "";
}

//constructor sets actor, month, and year
Classic::Classic(int month, int year, string actor) {
	this->actor = actor;
	this->month = month;
	this->year = year;
}

//default constructor
Classic::~Classic() {

}

//reads a line for classic movie and sets the data
string Classic::getActor(){
	return actor;
}

int Classic::getMonth(){
	return month;
}

void Classic::setData(string data) {
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
	string actorFirst, actorLast;
	dataStream >> actorFirst;
	dataStream >> actorLast;
	actor = actorFirst + " " + actorLast;
	dataStream >> month;
	dataStream >> year;

}

//displays a classic movie
void Classic::display() const {

	cout << "C, Stock: " << instock << ", Borrowed: "<< borrowedCount
			<< ", " << director << ", "  << title << ", " << actor
			<< ", " << month << " " <<  year <<  endl;

}

//checks if current classic movie is less than rhs
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

//checks if current classic movie is less than rhs
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

//checks if classic movies are equal
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

//checks if classic movies are equal
bool Classic::operator==(const Classic& rhs) const {
	if (month == rhs.month && year == rhs.year){
			if(actor == rhs.actor)
				return true;
			else if (title == rhs.title)
				return true;
		}
		return false;
}

