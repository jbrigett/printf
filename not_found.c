#include "ft_printf.h"

void	cs_not_found(t_format *frmt)
{
	frmt->width = (frmt->width > 0) ? frmt->width - 1 : 0;
	if (frmt->fl & MINUS)
		padding(frmt, (frmt->fl & ZERO) ? '0' : ' ', frmt->width);
	print_all(frmt, "%", 1);
	if (frmt->fl & ZERO)
		padding(frmt, ' ', frmt->width);
}