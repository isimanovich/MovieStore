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

public:
	Comedy();
	~Comedy();
	bool operator<(const Comedy&) const;
	bool operator==(const Comedy&) const;
	void setData();
	bool display() const;

private:


};



#endif /* COMEDY_H_ */
