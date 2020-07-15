#include "ft_printf.h"

void	print_aefg(t_format *frmt, t_buffer *buf)
{
	long double n;

	if (frmt->fl & LDOUBLE)
		n =  (long double)va_arg(frmt->ap, long double);
	else
		n = (double)va_arg(frmt->ap, double);
	!(frmt->fl & PRECISION) ? frmt->prec = 6 : 0;
	if (frmt->spec == 'a')
	{
		frmt->prec = (frmt->fl & UPPER) ? "0X" : "0x";
		print_ae(frmt, n, buf);
	}
	else if (frmt->spec == 'f')
		print_f(frmt, n, buf);
	else if (frmt->spec == 'g')
		print_g(n, frmt, buf);
	else if (frmt->spec == 'e')
		print_ae(frmt, n, buf);
}