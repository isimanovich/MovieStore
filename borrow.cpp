#include "borrow.h"
#include <sstream>
#include "movie.h"

using namespace std;

Borrow::Borrow() {

}

Borrow::~Borrow() {

}

void Borrow::setData(BinTree& tree, string data) {

	char mediaType = 'z';
	char movieType = 'z';
	string title = "", temp = "";
	int year = 0, month = 0;
	string dirFirstName = "", dirLastName = "";
	string actorFirst = "", actorLast = "";

	istringstream dataStream(data);		//opening stream

	dataStream >> mediaType;
	dataStream >> movieType;

	switch (movieType) {
	case 'F':

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
		dataStream >> year;

		Comedy* result = NULL;
		Movie* target = new Comedy(title, year);
		if(tree.retrieve(*target, result)) {
			//update stock
		} else {
			//not found
		}

		//DON"T FORGET TO DESTROY TEMPORARY OBJECTS

		break;
	case 'D':

		dataStream >> dirFirstName;			//reading first name
		dataStream >> dirLastName;			//reading last name
		dirLastName = dirLastName.substr(0, dirLastName.size() - 1);//removing comma after last name

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
	case 'C':
		dataStream >> month;
		dataStream >> year;
		dataStream >> actorFirst;
		dataStream >> actorLast;
		break;
	default:
		cout << "invalid type of movie, can't borrow" << endl;
		break;
	}

}

void Borrow::display() const {

}
