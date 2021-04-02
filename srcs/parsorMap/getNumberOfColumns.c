#include <stdlib.h>
#include "parsorMap.h"
#include "errorHandling.h"

static void	errorValidationNumberOfColumns(int numberOfColumns) {
	if (numberOfColumns < MIN_NUMBER_OF_COLUMNS) {
		throwErrorAndExit(ERROR_NUMBER_OF_COLUMNS_TOO_SMALL, numberOfColumns, MIN_NUMBER_OF_COLUMNS);
	} else {
		throwErrorAndExit(ERROR_NUMBER_OF_COLUMNS_TOO_BIG, numberOfColumns, MAX_NUMBER_OF_COLUMNS);
	}
}

static bool	hasValidNumberOfColumns(int numberOfColumns) {
	if (numberOfColumns >= MIN_NUMBER_OF_COLUMNS && numberOfColumns <= MAX_NUMBER_OF_COLUMNS) {
		return (true);
	}
	return (false);
}

int		getNumberOfColumns(FileReader *reader) {
	DigitStocker	stocker;
	int				numberOfColumns;
	state			currentState;

	initDigitStocker(&stocker);
	currentState = storeDigitsInBuffer(reader, &stocker);
	numberOfColumns = atoi(stocker.buffer);
	if (!hasValidNumberOfColumns(numberOfColumns)) {
		errorValidationNumberOfColumns(numberOfColumns);
	}
	return (numberOfColumns);
}