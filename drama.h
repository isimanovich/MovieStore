/*
 * drama.h
 *
 *  Created on: Nov 30, 2016
 *      Author: MacBook
 */

#ifndef DRAMA_H_
#define DRAMA_H_

#include "movie.h"
using namespace std;

class Drama: public Movie{

public:

	Drama();
	~Drama();
	 bool operator<(Drama&) const;
	 bool operator==(Drama& ) const;
     void setData(string);
	 bool display() const;

private:

};



#endif /* DRAMA_H_ */
