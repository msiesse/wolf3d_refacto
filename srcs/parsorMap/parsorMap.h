#ifndef PARSORMAP_H
# define PARSORMAP_H

# include "types.h"
# include "utilsFilesDescriptors.h"
# include "matrice.h"
# include "points.h"

# define ERROR_NUMBER_OF_DIGITS_TOO_BIG "Error: Exceed number of digits, max is %d\n"
# define ERROR_NOT_A_DIGIT "Error: %c is not a digit\n"
# define ERROR_NUMBER_OF_ROWS_TOO_SMALL "Error: %d is smaller than the minimum required number of rows %d\n"
# define ERROR_NUMBER_OF_ROWS_TOO_BIG "Error: %d is bigger than the maximum allowed number of rows %d\n"
# define ERROR_NUMBER_OF_COLUMNS_TOO_SMALL "Error: %d is smaller than the minimum required number of columns %d\n"
# define ERROR_NUMBER_OF_COLUMNS_TOO_BIG "Error: %d is bigger than the maximum allowed number of columns %d\n"
# define ERROR_NOT_VALID_VALUE_FOR_BYTE_MAP "Error: Not a valid map, should use 0 or 1. Should use 1 for borders\n"
# define ERROR_NOT_RIGHT_NUMBER_OF_COLUMNS "Error: Not right number of columns, expected %d, got %d\n"
# define ERROR_NOT_VALID_STARTING_POSITION "Error: position [ %d , %d ] is not a valid position\n"
# define ERROR_NOT_VALID_STARTING_ORIENTATION "Error: orientation %.1f is not a valid orientation: should be between 0 and 360\n"

# define STATE_PLAYER_START_IN_BORDER ""


# define MAX_NUMBER_OF_DIGITS 3
# define MIN_NUMBER_OF_ROWS 3
# define MAX_NUMBER_OF_ROWS 200
# define MIN_NUMBER_OF_COLUMNS 3
# define MAX_NUMBER_OF_COLUMNS 200
# define BAD_NUMBER -1


typedef struct	ParsorDataStocker {
	int			fd;
	int			numberOfRows;
	int			numberOfColumns;
	ByteMatrice	mapInBytes;
	IntPoint2D	playerPosition;
	angle		playerOrientation;
}				ParsorDataStocker;

typedef struct	DigitStocker {
	char	buffer[4];
	int		numberOfDigits;
}				DigitStocker;

// Here we choose to read the map like a real map and not like a 2D-array
// The origin is in top left
// Value of x rise when you go right
// Value of y rise when you go down

typedef struct	BytesMapStocker {
	ByteMatrice	*mapInBytes;
	IntPoint2D	currentPosInMap;
}				BytesMapStocker;

ParsorDataStocker 	parsor(const int fd);
ParsorDataStocker	initParsorDataStocker(const int fd);

int				getNextNumber(FileReader *reader);

void 			launchParsingOfDimensions(ParsorDataStocker *parsorStockerAddr, FileReader *reader);
void			ignoreCommentsAndEmptyLines(FileReader *reader);
void 			ignoreComment(FileReader *reader);
void			ignoreEmptyLines(FileReader *reader);

void			initDigitStocker(DigitStocker *stocker);
int				getNumberOfRows(FileReader *reader);
int				getNumberOfColumns(FileReader *reader);
state 			storeDigitsInBuffer(FileReader *reader, DigitStocker *stocker);
void			storeOneDigitInBuffer(byte digit, DigitStocker *stocker);

void			launchParsingOfMapBytes(ParsorDataStocker *parsorStockerAddr, FileReader *reader);
BytesMapStocker initBytesMapStocker(ByteMatrice *mapInBytes);

bool			isValidValueForMap(byte byteCursor, BytesMapStocker *stocker);
bool			isBorder(IntPoint2D point, ByteMatrice *map);

void			launchParsingOfPlayer(ParsorDataStocker *parsorStockerAddr, FileReader *reader);

void			printParsedMap(ParsorDataStocker stocker);

#endif