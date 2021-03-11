#include "parsorMap.h"
#include <stdio.h>

void launchParsingOfDimensions(ParsorMapFile *parsorMapFileAddr) {
	byte		byteCursor;
	FileReader	reader;

	byteCursor = initByteCursorFromFile(parsorMapFileAddr->fd);
	reader = initFileReader(parsorMapFileAddr->fd, byteCursor);
	ignoreAllCommentsAndEmptyLines(&reader);
	parsorMapFileAddr->numberOfLines = getNumberOfLines(&reader);
}