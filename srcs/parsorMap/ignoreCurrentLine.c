#include "parsorMap.h"
#include "characters.h"

static void ignoreCurrentLine(FileReader *reader) {
	while (isStandardCharacter(reader->byteCursor) && !isNewLine(reader->byteCursor)) {
		reader->byteCursor = readOneByte(reader->file);
	}
}

void	ignoreComment(FileReader *reader) {
	ignoreCurrentLine(reader);
}