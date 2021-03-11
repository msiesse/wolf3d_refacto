#ifndef UTILSFILESDESCRIPTORS_H
# define UTILSFILESDESCRIPTORS_H

# define STDIN_FD "/dev/fd/0"

# include "types.h"
# include <stdbool.h>

typedef struct	FileReader {
	byte	byteCursor;
	int		file;
}				FileReader;

FileReader	initFileReader(const int file, byte byteCursor);

int		openToReadStdinOrMapFile(int ac, char **av);
int     openToReadFile(char *pathToFile);
int     openToReadStdin(void);

byte	readOneByte(const int fd);
byte	initByteCursorFromFile(const int file);

bool	isEndOfFile(byte byteCursor);

#endif