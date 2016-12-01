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
    Movie();
    Movie(const Movie&);
    virtual ~Movie();


	virtual bool operator<(const Movie& ) const;
	virtual bool operator==(const Movie& ) const;
	virtual void setData();


	//consider passing line and decompose inside or full file,
	//but that probably should be in business
	virtual void setData(int, string, string, string, int);

	virtual bool display() const;
	void borrow();
	void returN();

	int getAmountIn();
	int getAmountOut();

protected:
	string dirFirstName;
	string dirLastName;
	int year;
	int instock;
	int borrowedCount;
	string title;
	string media;
};

#endif /* MOVIE_H_ */
