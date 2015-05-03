
#include <unistd.h>
#include "core.h"

void		error_callback(int error, const char *description)
{
	int		v;

	v = write(2, description, slen(description));
	(void)v;
	(void)error;
}
