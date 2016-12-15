// ---------------------------------------------- transaction.cpp ---------------------------------------------------
// Name: Ihar Simanovich & Jason Kozodoy
// Course: CSS343 A
// Creation Date: 12/01/2016
// Last Modification: 12/14/2016
// ------------------------------------------------------------------------------------------------------------------
// Purpose:
// ------------------------------------------------------------------------------------------------------------------
// Notes:
// ------------------------------------------------------------------------------------------------------------------
#include "transaction.h"
#include <sstream>

//defualt constructor sets default values
Transaction::Transaction() {
	type = 'T';
	year = 0;
	month = 0;
	success = true;
}

//defualt desctrutor
Transaction::~Transaction() {

}

void Transaction::doTransaction(BinTree& tree, char movieType) {

}

//transaction has been successful
bool Transaction::isSuccess(){
	return success;
}

//sets the type, year, and month for a movie depending
//on the type of movie
void Transaction::setData(string data, char movieType) {
	istringstream dataStream(data);		//opening stream
	type = 'B';
	switch (movieType) {
	case 'F': {
		string temp;
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
		//reading year
		dataStream >> year;
		break;
	}
	case 'D': {
		string temp;
		//reading director
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
		break;
	}
	case 'C': {
		string first, last;
		dataStream >> month;
		dataStream >> year;
		dataStream >> first;
		dataStream >> last;
		actor = first + " " + last;
		break;
	}
	default:
		cout << "invalid type of movie, can't do transaction" << endl;
		break;
	}

}

<<<<<<< HEAD
<<<<<<< HEAD
void Transaction::display() const {

}

//returns the transaction type
=======
>>>>>>> origin/master
=======
>>>>>>> origin/master
char Transaction::getTransType(){
	return type;
}

//returns the title
string Transaction::getTitle(){
	return title;
}

//returns the year
int Transaction::getYear(){
	return year;
}

//returns the month
int Transaction::getMonth(){
	return month;
}

//returns the director
string Transaction::getDirector(){
	return director;
}

//returns the actor
string Transaction::getActor(){
	return actor;
}
