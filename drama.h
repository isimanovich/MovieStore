
#ifndef DRAMA_H_
#define DRAMA_H_

#include "movie.h"
using namespace std;

//Drama Movie class that inherits from Movie
//Drama is just one of the genres in our store
class Drama: public Movie{

public:

	Drama();
	virtual ~Drama();
	Drama(string, string);
	bool operator<(const Movie&) const;
	bool operator<(const Drama&) const;
	bool operator==(const Drama& ) const;
	bool operator==(const Movie& ) const;

	void setData(string); //sets data for drama movie
	void display() const; //displays drama movie info

private:

};



#endif /* DRAMA_H_ */
