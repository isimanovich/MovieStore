#ifndef MEDIA_H_
#define MEDIA_H_

class Media {

public:

	Media();
	Media(const Media&);
	virtual ~Media();

	void increaseAmount();
	void decreaseAmount();
	int getAmountIn();
	int getAmountOut();

	virtual bool operator==(const Media&) const = 0;
	virtual bool operator<(const Media&) const = 0;

private:
	int numberOfStock;

};

#endif /* MEDIA_H_ */
