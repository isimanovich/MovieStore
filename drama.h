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

public:
	bool operator<(const Drama&) const;
	bool operator==(const Drama&) const;
	void setData();
	bool display() const;

private:

};



#endif /* DRAMA_H_ */
