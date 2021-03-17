#include "parsorMap.h"
#include "characters.h"

static void	ignoreNextCommentOrEmptyLines(FileReader *reader) {
	if (isSpaceOrNewLine(reader->byteCursor)) {
		ignoreEmptyLines(reader);
	} else if (isSharpCharacter(reader->byteCursor)) {
		ignoreComment(reader);
	} else {
		return ;
	}
}

static bool	hasToBeIgnored(byte byte) {
	if (isSpace(byte) || isNewLine(byte) || isSharpCharacter(byte)) {
		return (true);
	}
	return (false);
}

void	ignoreCommentsAndEmptyLines(FileReader *reader) {
	while (hasToBeIgnored(reader->byteCursor)) {
		ignoreNextCommentOrEmptyLines(reader);
	}
}