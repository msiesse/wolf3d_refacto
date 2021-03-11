#ifndef PARSORMAP_H
# define PARSORMAP_H

# include "types.h"
# include "utilsFilesDescriptors.h"
# include <stdbool.h>

# define ERROR_NUMBER_OF_DIGITS_TOO_BIG "Error: Exceed number of digits, max is %d\n"
# define ERROR_NOT_A_DIGIT "Error: %c is not a digit\n"
# define ERROR_NUMBER_OF_LINES_TOO_SMALL "Error: %d is smaller than the minimum required number of lines %d\n"
# define ERROR_NUMBER_OF_LINES_TOO_BIG "Error: %d is bigger than the maximum allowed number of lines %d\n"

# define MAX_NUMBER_OF_DIGITS 3
# define MIN_NUMBER_OF_LINES 3
# define MAX_NUMBER_OF_LINES 200


typedef struct	ParsorMapFile {
	int		fd;
	int		numberOfLines;
	int		numberOfColumns;
}				ParsorMapFile;

typedef struct	DigitStocker {
	char	buffer[4];
	int		numberOfDigits;
}				DigitStocker;

ParsorMapFile 	parsor(const int fd);
ParsorMapFile	initParsorMapFile(const int fd);

void 			launchParsingOfDimensions(ParsorMapFile *parsorMapFileAddr);
void			ignoreAllCommentsAndEmptyLines(FileReader *reader);
void 			ignoreComment(FileReader *reader);
void			ignoreEmptyLines(FileReader *reader);

void			initDigitStocker(DigitStocker *stocker);
int				getNumberOfLines(FileReader *reader);
void 			storeDigitsInBuffer(FileReader *reader, DigitStocker *stocker);
void			storeOneDigitInBuffer(byte digit, DigitStocker *stocker);

#endif