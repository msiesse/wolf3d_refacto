#include "utilsFilesDescriptors.h"

byte	initByteCursorFromFile(const int file) {
	byte	initByte;

	initByte = readOneByte(file);
	return (initByte);
}