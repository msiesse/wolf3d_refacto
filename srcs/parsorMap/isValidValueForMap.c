#include "parsorMap.h"
#include "characters.h"

bool	isValidValueForMap(byte byteCursor, BytesMapStocker *stocker) {
	if (byteCursor == '1' || isSpace(byteCursor)) {
		return (true);
	} else if (byteCursor == '0') {
		return (!isBorder(stocker->currentPosInMap, stocker->mapInBytes));
	}
	return (false);
}