#include "parsorMap.h"
#include <stdlib.h>

int				getNextNumber(FileReader *reader) {
	DigitStocker	stocker;
	state			currentState;

	ignoreCommentsAndEmptyLines(reader);
	initDigitStocker(&stocker);
	currentState = storeDigitsInBuffer(reader, &stocker);
	if (currentState == FAILURE) {
		return (BAD_NUMBER);
	}
	return (atoi(stocker.buffer));
}