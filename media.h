#ifndef MEDIA_H_
#define MEDIA_H_

#include <iostream>
using namespace std;

class Media {
public:
	Media();
	Media(const Media&);

	virtual ~Media();
	virtual void setData(istream&) = 0;
	virtual void setData2(istream&) = 0;
	virtual void display() const = 0;
	virtual void displayHeader() const= 0;
	virtual string getItem() const = 0;
	void setMaxCopies(const int);
	void increaseCopies();
	void decreaseCopies();
	int getAmountIn();
	int getAmountOut();

	virtual bool operator==(const Media&) const = 0;
	virtual bool operator<(const Media&) const = 0;
	virtual Media* doTransaction() = 0;

private:
	int maxCopies;
	int numberOfCopies;
};

#endif /* MEDIA_H_ */
