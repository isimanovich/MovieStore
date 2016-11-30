/*
 * drama.h
 *
 *  Created on: Nov 30, 2016
 *      Author: MacBook
 */

#ifndef DRAMA_H_
#define DRAMA_H_

using namespace std;

class Drama: public Movie{
	bool operator<() const;
	bool operator==() const;
	void setData();
	bool display() const;
};



#endif /* DRAMA_H_ */
