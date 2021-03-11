#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "utilsFilesDescriptors.h"

int     openToReadFile(char *pathToFile) {
    int fd;

    if ((fd = open(pathToFile, O_RDONLY)) < 0)
	{
		perror("wolf3d");
		exit(EXIT_FAILURE);
	}
	return (fd);
}