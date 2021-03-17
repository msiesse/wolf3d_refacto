#include "memoryHandler.h"
#include "matrice.h"
#include <stdlib.h>

void	partialFreeByteMapTopDown(ByteMatrice *mapInBytes, int topRow) {
	while (topRow) {
		topRow--;
		free(mapInBytes->map[topRow]);
	}
}

void	freeByteMatrice(ByteMatrice *byteMatrice) {
	for (int row = 0; row < byteMatrice->rows; row++) {
		free(byteMatrice->map[row]);
	}
}