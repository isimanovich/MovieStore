/*
 * movie.h
 *
 *  Created on: Nov 30, 2016
 *      Author: MacBook
 */

#ifndef MOVIE_H_
#define MOVIE_H_

#include "nodedata.h"
#include <iostream>
#include <string>


using namespace std;


class Movie: public NodeData{
public:
    Movie();				//default constructor
//    Movie(const Movie&);
    virtual ~Movie();

	virtual bool operator<(const Movie& ) const;
	virtual bool operator==(const Movie& ) const;


	//consider passing line and decompose inside or full file,
	//but that probably should be in business
	void setData(string);
    bool display() const;

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
