#include <fstream>
#include <iostream>

using namespace std;

int main () {


	// create file object infile and open it
	// for testing, call your data file something appropriate, e.g., data2.txt
	ifstream infile("data4movies.txt");
	if (!infile) {
		cout << "File could not be opened." << endl;
		return 1;
	}



	return 0;
}



