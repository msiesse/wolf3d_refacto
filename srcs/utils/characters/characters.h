#ifndef CHARACTERS_H
# define CHARACTERS_H

# include <stdbool.h>
# include "types.h"

bool	isSpace(char character);
bool	isNewLine(char character);
bool	isSharpCharacter(char character);
bool	isStandardCharacter(char character);
bool	isDigit(char character);
bool	isSpaceOrNewLine(char character);

#endif