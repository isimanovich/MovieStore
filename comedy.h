
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

private:


};



#endif /* COMEDY_H_ */
