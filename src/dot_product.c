
#include "core.h"

float		dot_product(t_vec const *v1, t_vec const *v2)
{
	return (v1->x * v2->x + v1->y * v2->y);
}
