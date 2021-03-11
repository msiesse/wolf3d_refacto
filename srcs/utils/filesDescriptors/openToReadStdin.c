#include "utilsFilesDescriptors.h"

int openToReadStdin(void) {
    int fd;

    fd = openToReadFile(STDIN_FD);
    return (fd);
}