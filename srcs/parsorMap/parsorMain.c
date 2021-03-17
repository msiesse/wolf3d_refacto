#include "parsorMap.h"

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
	return (stocker);
}