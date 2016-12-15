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

//Movie class
//Represents a movie in the store
class Movie{
public:
    Movie();				//default constructor
    virtual ~Movie();

    virtual bool operator<(const Movie &) const;
    virtual bool operator==(const Movie &) const;

	virtual void setData(string); //sets the movie data
    virtual void display() const; //displays info about movie

	bool borrow(); //a movie is borrowed
	void returN(); //a movie is returned


	int getAmountIn();
	int getAmountOut();

	string getTitle();
	int getYear();
	string getDirector();

	void increaseStock(int); //increase movie stock

protected:
	string director;
	int year;
	int instock;
	int borrowedCount;
	string title;
	string media;

};

#endif /* MOVIE_H_ */
