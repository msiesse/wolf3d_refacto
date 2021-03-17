#ifndef MATRICE_H
# define MATRICE_H

# include "types.h"

typedef struct	ByteMatrice {
	byte	**map;
	int		rows;
	int		columns;
}				ByteMatrice;

ByteMatrice	initByteMatrice(int rows, int columns);
void		partialFreeByteMapTopDown(ByteMatrice *mapInBytes, int topRow);
void		freeByteMatrice(ByteMatrice *byteMatrice);
void		printMatrice(ByteMatrice matrice);

#endif