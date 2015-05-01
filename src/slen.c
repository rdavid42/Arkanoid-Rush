
#include "core.h"

int			slen(char const *str)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
