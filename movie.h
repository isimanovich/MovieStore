/*
 * movie.h
 *
 *  Created on: Nov 30, 2016
 *      Author: MacBook
 */

#ifndef MOVIE_H_
#define MOVIE_H_

#include <iostream>
#include <string>


using namespace std;


class Movie{
public:
    Movie();				//default constructor
//    Movie(const Movie&);
    virtual ~Movie();

    virtual bool operator>(const Movie &) const;
    virtual bool operator<(const Movie &) const;
    virtual bool operator==(const Movie &) const;


	//consider passing line and decompose inside or full file,
	//but that probably should be in business
	virtual void setData(string);
    bool display() const;

	void borrow();
	void returN();


	int getAmountIn();
	int getAmountOut();

	string getTitle();
	int getYear();
	string getDirector();


	void increaseStock(int);

protected:
	string director;
	int year;
	int instock;
	int borrowedCount;
	string title;
	string media;

};

#endif /* MOVIE_H_ */
