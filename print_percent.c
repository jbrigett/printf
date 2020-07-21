#include "ft_printf.h"


int	print_percent(t_format *frmt)
{
	if (!(frmt->fl & MINUS) && frmt->width > 1)
		padding(frmt, (frmt->fl & ZERO) ? '0' : ' ', frmt->width - 1);
	print_all(frmt, "%", 1);
	if (frmt->fl & MINUS && frmt->width > 0)
		padding(frmt, ' ', frmt->width - 1);
}