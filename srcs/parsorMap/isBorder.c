#include "parsorMap.h"

bool	isBorder(IntPoint2D point, ByteMatrice *map) {
	if (point.x == 0 || point.x == map->columns - 1 ||
		point.y == 0 || point.y == map->rows - 1) {
		return (true);
	}
	return (false);
}