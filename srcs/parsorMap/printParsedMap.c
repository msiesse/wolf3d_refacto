#include <stdio.h>
#include "parsorMap.h"

void	printParsedMap(ParsorDataStocker stocker) {
	printf("Number of rows: %d\n", stocker.numberOfRows);
	printf("Number of columns: %d\n", stocker.numberOfColumns);
	printf("-------- MAP --------\n\n");
	printMatrice(stocker.mapInBytes);
	printf("\n");
	printf("---------------------\n\n");
	printf("Player position: [ %d , %d ]\n", stocker.playerPosition.x, stocker.playerPosition.y);
	printf("Player orientation: %.1f\n", stocker.playerOrientation);
}