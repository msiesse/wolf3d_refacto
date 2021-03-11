#ifndef ERROR_HANDLING_H
# define ERROR_HANDLING_H

void	throwError(const char *format, ...);
void	throwErrorAndExit(const char *format, ...);

#endif