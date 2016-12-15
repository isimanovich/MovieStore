// -------------------------------------------------- comedy.h ------------------------------------------------------
// Name: Ihar Simanovich & Jason Kozodoy
// Course: CSS343 A
// Creation Date: 12/01/2016
// Last Modification: 12/14/2016
// ------------------------------------------------------------------------------------------------------------------
#ifndef COMEDY_H_
#define COMEDY_H_

#include "movie.h"
using namespace std;

//Comedy Movie class that inherits from Movie
//Comedy is just one of the genres in our store
class Comedy: public Movie{

public:
	Comedy();
	Comedy(string, int);
	virtual ~Comedy();
	bool operator<(const Movie&) const;
	bool operator<(const Comedy&) const;
	bool operator==(const Movie&) const;
	bool operator==(const Comedy&) const;

	void setData(string); //sets the comedy movie data
	void display() const; //displays comedy movie info
};



#endif /* COMEDY_H_ */
