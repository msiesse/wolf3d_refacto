#include "parsorMap.h"

ParsorMapFile	initParsorMapFile(const int fd) {
	ParsorMapFile	newParsorMapFile;

	newParsorMapFile.numberOfColumns = 0;
	newParsorMapFile.numberOfLines = 0;
	newParsorMapFile.fd = fd;
	
	return (newParsorMapFile);
}