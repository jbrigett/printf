#include "ft_printf.h"

void	print_p(t_format *frmt)
{
	void		*ptr;
	uintmax_t	nb;

	ptr = va_arg(frmt->ap, void *);
	nb = (uintmax_t)ptr;
	frmt->base = 16;
	frmt->pref = "0x";
	frmt->fl |= POINTER;
	frmt->fl |= SHARP;
	settings_bxou(nb, frmt);
}