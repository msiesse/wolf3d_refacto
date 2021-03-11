#include <stdlib.h>
#include "parsorMap.h"
#include "errorHandling.h"

static void	errorValidationNumberOfLines(int numberOfLines) {
	if (numberOfLines < MIN_NUMBER_OF_LINES) {
		throwErrorAndExit(ERROR_NUMBER_OF_LINES_TOO_SMALL, numberOfLines, MIN_NUMBER_OF_LINES);
	} else {
		throwErrorAndExit(ERROR_NUMBER_OF_LINES_TOO_BIG, numberOfLines, MAX_NUMBER_OF_LINES);
	}
}

static bool	hasValidNumberOfLines(int numberOfLines) {
	if (numberOfLines >= MIN_NUMBER_OF_LINES && numberOfLines <= MAX_NUMBER_OF_LINES) {
		return (true);
	}
	return (false);
}

int		getNumberOfLines(FileReader *reader) {
	DigitStocker	stocker;
	int				numberOfLines;

	initDigitStocker(&stocker);
	storeDigitsInBuffer(reader, &stocker);
	numberOfLines = atoi(stocker.buffer);
	if (!hasValidNumberOfLines(numberOfLines)) {
		errorValidationNumberOfLines(numberOfLines);
	}
	return (numberOfLines);
}