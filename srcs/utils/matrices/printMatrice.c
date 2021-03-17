#include <stdio.h>
#include "matrice.h"

void	printMatrice(ByteMatrice matrice) {
	for (int row = 0; row < matrice.rows; row++) {
		printf ("| ");
		for (int col = 0; col < matrice.columns; col++) {
			printf("%c ", matrice.map[row][col]);
		}
		printf("|\n");
	}
}