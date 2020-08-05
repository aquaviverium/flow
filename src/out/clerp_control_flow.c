#include "out.h"

#define C_SCALE (1)

void	set_color(int val, int *r, int *g, int *b)
{
	int result;

	result = 0;
	if (val < 10 * C_SCALE)
		result = clerp(0x33FF00, 0x00FF00, val - 0 * C_SCALE, 10 * C_SCALE);
	else if (val < 50 * C_SCALE)
		result = clerp(0x00FF00, 0x00FFFF, val - 10 * C_SCALE, 40 * C_SCALE);
	else if (val < 100 * C_SCALE)
		result = clerp(0x00FFFF, 0x6633FF, val - 50 * C_SCALE, 50 * C_SCALE);
	else if (val < 200 * C_SCALE)
		result = clerp(0x6633FF, 0x000000, val - 100 * C_SCALE, 100 * C_SCALE);
	ctoRGB(result, r, g, b);
}
