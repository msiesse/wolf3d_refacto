#include "parsorMap.h"
#include "characters.h"

void	ignoreEmptyLines(FileReader *reader) {
	while (isSpaceOrNewLine(reader->byteCursor)) {
		reader->byteCursor = readOneByte(reader->file);
	}
}