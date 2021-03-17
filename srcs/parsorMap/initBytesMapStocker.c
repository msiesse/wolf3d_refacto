#include "parsorMap.h"

BytesMapStocker initBytesMapStocker(ByteMatrice *mapInBytes) {
	BytesMapStocker	stocker;

	stocker.mapInBytes = mapInBytes;
	return (stocker);
}