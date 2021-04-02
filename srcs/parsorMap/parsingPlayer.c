#include "parsorMap.h"
#include "errorHandling.h"

static bool	isPositionOutOfBounds(ByteMatrice *mapInBytes, IntPoint2D position) {
	if (position.x < 0 || position.y < 0 || 
		position.x >= mapInBytes->columns || position.y >= mapInBytes->rows) {
			return (true);
	}
	return (false);
}

static bool	isPositionInWall(ByteMatrice *mapInBytes, IntPoint2D position) {
	if (mapInBytes->map[position.y][position.x] == '1') {
		return (true);
	}
	return (false);
}

static bool			isValidStartingPosition(ByteMatrice *mapInBytes, IntPoint2D position) {
	if (isPositionOutOfBounds(mapInBytes, position) || isPositionInWall(mapInBytes, position)) {
		return (false);
	}
	return (true);
}

static IntPoint2D		getPlayerStartingPosition(ByteMatrice *mapInBytes, FileReader *reader) {
	IntPoint2D	position;

	position.x = getNextNumber(reader);
	position.y = getNextNumber(reader);
	if (!isValidStartingPosition(mapInBytes, position)) {
		freeByteMatrice(mapInBytes);
		throwErrorAndExit(ERROR_NOT_VALID_STARTING_POSITION, position.x, position.y);
	}
	return (position);
}

static angle			getPlayerStartingOrientation(ByteMatrice *mpaInBytes, FileReader *reader) {
	angle	orientation;

	orientation = (angle)getNextNumber(reader);
	if (orientation < 0 || orientation > 360) {
		freeByteMatrice(mpaInBytes);
		throwErrorAndExit(ERROR_NOT_VALID_STARTING_ORIENTATION, orientation);
	}
	return (orientation);
}

void	launchParsingOfPlayer(ParsorDataStocker *parsorStockerAddr, FileReader *reader) {
	parsorStockerAddr->playerPosition = getPlayerStartingPosition(&(parsorStockerAddr->mapInBytes), reader);
	parsorStockerAddr->playerOrientation = getPlayerStartingOrientation(&(parsorStockerAddr->mapInBytes), reader);
}