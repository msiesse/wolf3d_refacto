#include "parsorMap.h"
#include "characters.h"
#include "errorHandling.h"
#include <stdio.h>

static void	errorGettingDigit(FileReader *reader, DigitStocker *stocker) {
	if (stocker->numberOfDigits >= MAX_NUMBER_OF_DIGITS) {
		throwErrorAndExit(ERROR_NUMBER_OF_DIGITS_TOO_BIG, MAX_NUMBER_OF_DIGITS);
	} else {
		throwErrorAndExit(ERROR_NOT_A_DIGIT, reader->byteCursor);
	}
}

static bool	getCurrentDigit(FileReader *reader, DigitStocker *stocker) {
	if (isDigit(reader->byteCursor) && stocker->numberOfDigits < MAX_NUMBER_OF_DIGITS) {
		storeOneDigitInBuffer(reader->byteCursor, stocker);
		return (true);
	}
	return (false);
}

state	storeDigitsInBuffer(FileReader *reader, DigitStocker *stocker) {
	while (!isEndOfFile(reader->byteCursor) && !isSpaceOrNewLine(reader->byteCursor)) {
		if (getCurrentDigit(reader, stocker)) {
			reader->byteCursor = readOneByte(reader->file);
		} else {
			errorGettingDigit(reader, stocker);
			return (FAILURE);
		}
	}
	return (SUCCESS);
}