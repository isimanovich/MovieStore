/*
 * classic.h
 *
 *  Created on: Nov 30, 2016
 *      Author: MacBook
 */

#ifndef CLASSIC_H_
#define CLASSIC_H_

using namespace std;

class Classic: public Movie{
public:
	bool operator<() const;
	bool operator==() const;
	void setData();
	bool display() const;
private:
	string actorFirst;
	string actorLast;
	int month;
};



#endif /* CLASSIC_H_ */
