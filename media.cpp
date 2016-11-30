#include "media.h"

Media::Media() :
		numberOfCopies(-1), maxCopies(0)
{
}

Media::~Media() {
}

void Media::decreaseCopies() {
	if (numberOfCopies != 0)
		numberOfCopies = numberOfCopies - 1;
}

void Media::increaseCopies() {
	if (numberOfCopies != maxCopies)
		numberOfCopies = numberOfCopies + 1;
}

int Media::getAmountIn() {
	return numberOfCopies;
}

int Media::getAmountOut() {
	return maxCopies - numberOfCopies;
}

void Media::setMaxCopies(const int amountIn) {
	maxCopies = amountIn;

	if (numberOfCopies < 0)
		numberOfCopies = maxCopies;
}
