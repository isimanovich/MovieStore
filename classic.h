// ------------------------------------------------- classic.h ------------------------------------------------------
// Name: Ihar Simanovich & Jason Kozodoy
// Course: CSS343 A
// Creation Date: 12/01/2016
// Last Modification: 12/14/2016
// ------------------------------------------------------------------------------------------------------------------
// Purpose:
// ------------------------------------------------------------------------------------------------------------------
// Notes:
// ------------------------------------------------------------------------------------------------------------------

#ifndef CLASSIC_H_
#define CLASSIC_H_

#include "movie.h"
using namespace std;

//Classic Movie class inherits from movie
//Classic is one of the geners at our store
class Classic: public Movie{
public:
	Classic();
	virtual ~Classic();
	Classic(int, int, string);
	bool operator<(const Movie&) const;
	bool operator<(const Classic&) const;
	bool operator==(const Classic&) const;
	bool operator==(const Movie&) const;

	void setData(string); //sets classic movie data
	void display() const; //displays classic movie info

	string getActor();
	int getMonth();

protected:
	string actor;
	int month;
};



#endif /* CLASSIC_H_ */
