#include "borrow.h"
#include <sstream>
#include "movie.h"

using namespace std;

Borrow::Borrow() {

}

Borrow::~Borrow() {

}

void Borrow::setData(BinTree& tree, string data, char movieType) {

	istringstream dataStream(data);		//opening stream

	switch (movieType) {
	case 'F': {
		int year;
		string title, temp;
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

		Movie* result = NULL;
		Comedy* target = new Comedy(title, year);
		if (tree.retrieve(*target, result)) {
			if (result->borrow() == false) {
				cout << "ERROR: THIS MOVIE IS OUT OF STOCK" << endl;
			}

		} else {
			cout << "ERROR: MOVIE IS NOT FOUND IN COLLECTION OF COMEDIES" << endl;
		}

		//DON"T FORGET TO DESTROY TEMPORARY OBJECTS

		break;
	}
	case 'D': {
		string title, temp;
		string director;
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

		Movie* result = NULL;
		Drama* target = new Drama(director, title);

		if (tree.retrieve(*target, result)) {
			if (result->borrow() == false) {
				cout << "ERROR: THIS MOVIE IS OUT OF STOCK" << endl;
			}
		} else {
			cout << "ERROR: MOVIE IS NOT FOUND IN COLLECTION OF DRAMAS" << endl;
		}

		//DON"T FORGET TO DESTROY TEMPORARY OBJECTS

		break;
	}
	case 'C': {
		string actor, first, last;
		int year, month;
		dataStream >> month;
		dataStream >> year;
		dataStream >> first;
		dataStream >> last;
		actor = first + " " + last;

		Movie* result = NULL;
		Classic* target = new Classic(month, year, actor);
		if (tree.retrieve(*target, result)) {
			if (result->borrow() == false) {
				cout << "ERROR: THIS MOVIE IS OUT OF STOCK" << endl;
			}
		} else {
			cout << "ERROR: MOVIE IS NOT FOUND IN COLLECTION OF CLASSICS" << endl;
		}
		//DON"T FORGET TO DESTROY TEMPORARY OBJECTS
		break;
	}
	default:
		cout << "invalid type of movie, can't borrow" << endl;
		break;
	}

}

void Borrow::display() const {

}
