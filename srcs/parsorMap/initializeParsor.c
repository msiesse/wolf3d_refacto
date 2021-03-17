#include "parsorMap.h"

ParsorDataStocker	initParsorDataStocker(const int fd) {
	ParsorDataStocker	stocker;

	stocker.numberOfColumns = 0;
	stocker.numberOfRows = 0;
	stocker.fd = fd;
	
	return (stocker);
}