/*
 * movie.h
 *
 *  Created on: Nov 30, 2016
 *      Author: MacBook
 */

#ifndef MOVIE_H_
#define MOVIE_H_

using namespace std;

class Movie: public NodeData {
public:
	virtual bool operator<(const Movie& ) const;
	virtual bool operator==(const Movie& ) const;
	virtual void setData();
	virtual bool display() const;
	void borrow();
	void returN();

protected:
	string dirFirstName;
	string dirLastName;
	int year;
	int instock;
	string title;
	string media;
};

#endif /* MOVIE_H_ */
