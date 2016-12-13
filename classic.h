/*
 * classic.h
 *
 *  Created on: Nov 30, 2016
 *      Author: MacBook
 */



#ifndef CLASSIC_H_
#define CLASSIC_H_

#include "movie.h"
using namespace std;

class Classic: public Movie{
public:
	Classic();
	virtual ~Classic();
	Classic(int, int, string);
	bool operator<(const Classic&) const;
	bool operator>(const Classic&) const;
	bool operator==(const Classic&) const;

	void setData(string);
	bool display() const;
protected:
	string actor;
	int month;
};



#endif /* CLASSIC_H_ */
