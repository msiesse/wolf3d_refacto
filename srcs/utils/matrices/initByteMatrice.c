#include "matrice.h"
#include "memoryHandler.h"
#include "errorHandling.h"
#include <stdlib.h>

ByteMatrice	initByteMatrice(int rows, int columns) {
	ByteMatrice		byteMatrice;

	byteMatrice.rows = rows;
	byteMatrice.columns = columns;
	if (!(byteMatrice.map = (byte**)malloc(rows * sizeof(byte*)))) {
		throwErrorAndExit(ERROR_ALLOC, "byteMatrice.map");
	}
	for (int currentRow = 0; currentRow < rows; currentRow++) {
		if (!(byteMatrice.map[currentRow] = (byte*)malloc(columns * sizeof(byte)))) {
			partialFreeByteMapTopDown(&byteMatrice, currentRow);
			free(byteMatrice.map);
			throwErrorAndExit(ERROR_ALLOC_COLUMNS, "byteMatrice.map[i] with i = ", currentRow);
		}
	}
	return (byteMatrice);
}