#include "movie.h"
#include <sstream>

using namespace std;

//default constructor
//setting private data members to its default values
Movie::Movie() {
	borrowedCount = 0;
	dirFirstName = "";
	dirLastName = "";
	instock = 0;
	media = "DVD";
	title = "";
	year = 0;
}

//still need destructor

void Movie::borrow() {
	this->instock--;
}

void Movie::returN() {
	this->instock++;
}

bool Movie::operator<(const Movie &rhs) const {
	if (this->title < rhs.title)
		return true;
	else
		return false;
}

bool Movie::operator==(const Movie& rhs) const {
	if (this->title == rhs.title)
		return true;
	else
		return false;
}

//consider passing line and decompose inside or full file,
//but that probably should be in business
void Movie::setData(string data) {

	istringstream dataStream(data);		//opening stream
	dataStream.ignore(256, ' ');		//ignoring first comma
	dataStream >> instock;				//getting quantity in stock
	cout << instock << endl;
	dataStream.ignore(256, ',');		//ignoring comma after number
	dataStream >> dirFirstName;			//reading first name
	dataStream >> dirLastName;			//reading last name

	dirLastName = dirLastName.substr(0, dirLastName.size() - 1);//removing comma after last name
	cout << dirFirstName << endl;
	cout << dirLastName << endl;

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
	cout << title << endl;

	//getting a year of the movie
	dataStream >> year;
	cout << year << endl;
}
