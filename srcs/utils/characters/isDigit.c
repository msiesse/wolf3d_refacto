#include "characters.h"

bool	isDigit(char character) {
	if (character >= '0' && character <= '9') {
		return (true);
	}
	return (false);
}