#include "characters.h"

bool	isSpaceOrNewLine(char character) {
	if (isSpace(character) || isNewLine(character)) {
		return (true);
	}
	return (false);
}