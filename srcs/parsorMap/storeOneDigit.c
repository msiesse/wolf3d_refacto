#include "parsorMap.h"

void	storeOneDigitInBuffer(byte digit, DigitStocker *stocker) {
	int	index;

	index = stocker->numberOfDigits;
	stocker->buffer[index] = digit;
	stocker->numberOfDigits++;
}