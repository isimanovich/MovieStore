#include <fstream>
#include <iostream>
#include "business.h"

using namespace std;

int main() {

	// create file object infile and open it
	// for testing, call your data file something appropriate, e.g., data2.txt
	ifstream movieFile("src/data4movies.txt");
	if (!movieFile) {
		cout << "Movie file could not be opened." << endl;
		return 1;
	}

	ifstream custFile("src/data4customers.txt");
	if (!custFile) {
		cout << "Customers file could not be opened." << endl;
		return 1;
	}

	ifstream comFile("src/data4commands.txt");
	if (!comFile) {
		cout << "Commands file could not be opened." << endl;
		return 1;
	}

	Business store;

	store.buildMovies(movieFile);

	store.processTransactions(comFile);



	return 0;
}

