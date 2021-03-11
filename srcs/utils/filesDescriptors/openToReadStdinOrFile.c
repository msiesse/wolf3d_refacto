#include "utilsFilesDescriptors.h"

int	openToReadStdinOrMapFile(int ac, char **av) {
	int		fd;
	char	*pathToMapFile;

	if (ac == 1) {
        fd = openToReadStdin();
    } else {
        pathToMapFile = av[1];
        fd = openToReadFile(pathToMapFile);
    }

	return (fd);
}