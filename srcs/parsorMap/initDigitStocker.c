#include "parsorMap.h"
#include <strings.h>

void	initDigitStocker(DigitStocker *stocker) {
	stocker->numberOfDigits = 0;
	bzero(stocker->buffer, 4);
}