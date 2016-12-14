#include "return.h"
#include "movie.h"
#include <sstream>

using namespace std;

Return::Return() {
	type = 'R';
}

Return::~Return() {

}

void Return::doTransaction(BinTree& tree, char movieType) {

	Movie* result = NULL;

	switch (movieType) {
	case 'F': {

		Comedy* target = new Comedy(title, year);
		if (tree.retrieve(*target, result))
			result->returN();
		else {
			cout << "ERROR: MOVIE IS NOT FOUND IN COLLECTION OF COMEDIES"
					<< endl;
		}

		//DON"T FORGET TO DESTROY TEMPORARY OBJECTS
		break;
	}
	case 'D': {
		Drama* target = new Drama(director, title);

		if (tree.retrieve(*target, result))
			result->returN();
		else {
			cout << "ERROR: MOVIE IS NOT FOUND IN COLLECTION OF DRAMAS" << endl;
		}

		//DON"T FORGET TO DESTROY TEMPORARY OBJECTS

		break;
	}
	case 'C': {
		Classic* target = new Classic(month, year, actor);
		if (tree.retrieve(*target, result))
			result->returN();
		else {
			cout << "ERROR: MOVIE IS NOT FOUND IN COLLECTION OF CLASSICS"
					<< endl;
		}
		//DON"T FORGET TO DESTROY TEMPORARY OBJECTS
		break;
	}
	default:
		cout << "invalid type of movie, can't return" << endl;
		break;
	}

	//reset data based on performed transaction
	if (result != NULL) {
		title = result->getTitle();
		year = result->getYear();
	}

}

void Return::setData(string data, char movieType) {

	istringstream dataStream(data);		//opening stream
	type = 'R';
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
		cout << "invalid type of movie, can't set data" << endl;
		break;
	}

}

void Return::display() const {

}
