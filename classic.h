/*
 * classic.h
 *
 *  Created on: Nov 30, 2016
 *      Author: MacBook
 */



#ifndef CLASSIC_H_
#define CLASSIC_H_
#include <iostream>
#include "movie.h"
using namespace std;

class Classic: public Movie{
public:
	Classic();
	virtual ~Classic();

	bool operator<(const Classic&) const;
	bool operator==(const Classic&) const;
	void setData(string);
	bool display() const;
private:
	string actorFirst;
	string actorLast;
	int month;
};



#endif /* CLASSIC_H_ */
