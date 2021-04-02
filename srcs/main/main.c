#include <fcntl.h>
#include <unistd.h>
#include "utilsFilesDescriptors.h"
#include "parsorMap.h"

int main(int ac, char **av) {
    int     fd;
	ParsorDataStocker	stocker;

	fd = openToReadStdinOrMapFile(ac, av);

	stocker = parsor(fd);
	close(fd);
	printParsedMap(stocker);
	freeByteMatrice(&stocker.mapInBytes);
    return (0);
}