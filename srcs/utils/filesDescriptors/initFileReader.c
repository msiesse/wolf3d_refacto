#include "utilsFilesDescriptors.h"
#include <stdlib.h>
#include <stdio.h>

FileReader	initFileReader(const int file, byte byteCursor) {
	FileReader	reader;

	reader.file = file;
	reader.byteCursor = byteCursor;
	return (reader);
}