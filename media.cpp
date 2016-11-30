#include "media.h"

Media::Media() :
		numberOfCopies(-1)
{
}

Media::~Media() {
}

void Media::decreaseCopies() {
	if (numberOfCopies != 0)
		numberOfCopies = numberOfCopies - 1;
}

void Media::increaseCopies() {
		numberOfCopies = numberOfCopies + 1;
}

int Media::getAmountIn() {
	return numberOfCopies;
}

int Media::getAmountOut() {
	return maxCopies - numberOfCopies;
}


