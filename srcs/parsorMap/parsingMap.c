#include "parsorMap.h"
#include "characters.h"
#include "points.h"
#include "errorHandling.h"

static bool	isRightNumberOfColumns(int numberOfColumns, int expectedValueOfColumns) {
	if (numberOfColumns == expectedValueOfColumns) {
		return (true);
	}
	return (false);
}

static void	storeOrIgnoreValue(BytesMapStocker *stocker, FileReader *reader) {
	if (reader->byteCursor != ' ') {
		stocker->mapInBytes->map[stocker->currentPosInMap.y][stocker->currentPosInMap.x] = reader->byteCursor;
		stocker->currentPosInMap.x++;
	}
	reader->byteCursor = readOneByte(reader->file);
}

static void	storeOneLineOfMap(BytesMapStocker *stocker, FileReader *reader) {
	stocker->currentPosInMap.x = 0;

	ignoreCommentsAndEmptyLines(reader);
	while (!isEndOfFile(reader->byteCursor) && !isNewLine(reader->byteCursor)) {
		if (isValidValueForMap(reader->byteCursor, stocker)) {
			storeOrIgnoreValue(stocker, reader);
		} else {
			freeByteMatrice(stocker->mapInBytes);
			throwErrorAndExit(ERROR_NOT_VALID_VALUE_FOR_BYTE_MAP);
		}
	}
}

void	launchParsingOfMapBytes(ParsorDataStocker *parsorStockerAddr, FileReader *reader) {
	BytesMapStocker	stocker;

	stocker = initBytesMapStocker(&parsorStockerAddr->mapInBytes);
	for (stocker.currentPosInMap.y = 0; stocker.currentPosInMap.y < stocker.mapInBytes->rows; stocker.currentPosInMap.y++) {
		storeOneLineOfMap(&stocker, reader);
		if (!isRightNumberOfColumns(stocker.currentPosInMap.x, stocker.mapInBytes->columns)) {
			freeByteMatrice(stocker.mapInBytes);
			throwErrorAndExit(ERROR_NOT_RIGHT_NUMBER_OF_COLUMNS, stocker.mapInBytes->columns, stocker.currentPosInMap.x);
		}
	}
}