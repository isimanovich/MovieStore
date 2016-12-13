/*
 * comedy.h
 *
 *  Created on: Nov 30, 2016
 *      Author: MacBook
 */

#ifndef COMEDY_H_
#define COMEDY_H_

#include "movie.h"
using namespace std;



class Comedy: public Movie{

public:
	Comedy();
	Comedy(string, int);
	virtual ~Comedy();
	bool operator<(const Movie&) const;
	bool operator<(const Comedy&) const;
	bool operator==(const Movie&) const;
	bool operator==(const Comedy&) const;

	void setData(string);
	void display() const;

private:


};



#endif /* COMEDY_H_ */
