#include "ft_printf.h"

void	cs_not_found(t_format *frmt)
{


	if ((frmt->padding = frmt->min_length - 1) > 0)
	{
		padding(frmt, 0);
		buffer(frmt, frmt->format, 1);
		padding(frmt, 1);
	}
	else
		buffer(frmt, frmt->format, 1);
}