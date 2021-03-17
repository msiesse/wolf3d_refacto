#include <stdlib.h>
#include "parsorMap.h"
#include "errorHandling.h"

static void	errorValidationNumberOfRows(int numberOfRows) {
	if (numberOfRows < MIN_NUMBER_OF_ROWS) {
		throwErrorAndExit(ERROR_NUMBER_OF_ROWS_TOO_SMALL, numberOfRows, MIN_NUMBER_OF_ROWS);
	} else {
		throwErrorAndExit(ERROR_NUMBER_OF_ROWS_TOO_BIG, numberOfRows, MAX_NUMBER_OF_ROWS);
	}
}

static bool	hasValidNumberOfRows(int numberOfRows) {
	if (numberOfRows >= MIN_NUMBER_OF_ROWS && numberOfRows <= MAX_NUMBER_OF_ROWS) {
		return (true);
	}
	return (false);
}

int		getNumberOfRows(FileReader *reader) {
	DigitStocker	stocker;
	int				numberOfRows;

	initDigitStocker(&stocker);
	storeDigitsInBuffer(reader, &stocker);
	numberOfRows = atoi(stocker.buffer);
	if (!hasValidNumberOfRows(numberOfRows)) {
		errorValidationNumberOfRows(numberOfRows);
	}
	return (numberOfRows);
}