#include "errorHandling.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

void	throwError(const char *format, ...) {
	va_list	args;

	va_start(args, format);
	vdprintf(2, format, args);
	va_end(args);
}

void	throwErrorAndExit(const char *format, ...) {
	va_list	args;

	va_start(args, format);
	vdprintf(2, format, args);
	va_end(args);
	exit(EXIT_FAILURE);
}