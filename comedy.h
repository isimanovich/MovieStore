/*
 * comedy.h
 *
 *  Created on: Nov 30, 2016
 *      Author: MacBook
 */

#ifndef COMEDY_H_
#define COMEDY_H_

using namespace std;

class Comedy: public Movie{
	bool operator<() const;
	bool operator==() const;
	void setData();
	bool display() const;
};



#endif /* COMEDY_H_ */
