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
	actorFirst = "";
	actorLast = "";
}

Classic::~Classic(){

}

void Classic::setData(string data){

//	cout << "this is what i get for classic: " << endl;
//	cout << data << endl;

	istringstream dataStream(data);		//opening stream
	dataStream.ignore(256, ' ');		//ignoring first comma
	dataStream >> instock;				//getting quantity in stock
//	cout << instock << endl;
	dataStream.ignore(256, ',');		//ignoring comma after number
	dataStream >> dirFirstName;			//reading first name
	dataStream >> dirLastName;			//reading last name

	dirLastName = dirLastName.substr(0, dirLastName.size() - 1);//removing comma after last name
//	cout << dirFirstName << endl;
//	cout << dirLastName << endl;

	//reading title
	string temp;
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
//	cout << title << endl;
	this->data = title;			//setting data to title name, so node can be stored in the tree
	//getting a year of the movie
	dataStream >> actorFirst;
	dataStream >> actorLast;
	dataStream >> month;
	dataStream >> year;
//	cout << year << endl;



}

bool Classic::display()const{
	return false;
}
