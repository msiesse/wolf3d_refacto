#include "types.h"
#include "utilsFilesDescriptors.h"
#include "libft.h"

byte	readOneByte(const int fd) {
	byte byte;

	byte = ft_fgetc(fd);
	return (byte); 
}