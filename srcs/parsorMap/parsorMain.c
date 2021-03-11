#include "parsorMap.h"

ParsorMapFile parsor(const int fd) {
	ParsorMapFile	parsorMapFile;

	parsorMapFile = initParsorMapFile(fd);
	launchParsingOfDimensions(&parsorMapFile);
	return (parsorMapFile);
}