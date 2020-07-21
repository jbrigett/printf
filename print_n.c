#include "ft_printf.h"

void	print_n(t_format *format)
{
	*va_arg(format->ap, int *) = format->len;
}