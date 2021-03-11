#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "utilsFilesDescriptors.h"
#include "parsorMap.h"

int main(int ac, char **av) {
    int     fd;

	fd = openToReadStdinOrMapFile(ac, av);

	parsor(fd);
    return (0);
}