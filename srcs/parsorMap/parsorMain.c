#include "parsorMap.h"
#include <stdio.h>

ParsorDataStocker parsor(const int fd) {
	ParsorDataStocker	stocker;
	byte				byteCursor;
	FileReader			reader;

	stocker = initParsorDataStocker(fd);
	byteCursor = initByteCursorFromFile(stocker.fd);
	reader = initFileReader(stocker.fd, byteCursor);
	launchParsingOfDimensions(&stocker, &reader);
	stocker.mapInBytes = initByteMatrice(stocker.numberOfRows, stocker.numberOfColumns);
	launchParsingOfMapBytes(&stocker, &reader);
	launchParsingOfPlayer(&stocker, &reader);
	return (stocker);
}