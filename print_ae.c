#include "ft_printf.h"

void	set_exp(t_format *frmt, int64_t *exp, long double n)
{
	*exp = 0;
	if (n < 1 && n != 0)
		while (n < 1)
		{
			*exp -= 1;
			n *= (frmt->base == 10) ? frmt->base : 2;
		}
	else if (n >= 1)
		while (n > (frmt->base == 10) ? frmt->base - 1 : 2)
		{
			*exp += 1;
			n *= (frmt->base == 10) ? frmt->base : 2;
		}
}

void	print_exp(int64_t exp, uintmax_t n, t_format *frmt, t_buffer *buf)
{
	if (frmt->base == 16)
		PRINT((frmt->fl & UPPER) ? "P" : "p", 1, buf);
	else
		PRINT((frmt->fl & UPPER) ? "E" : "e", 1, buf);
	PRINT((exp >= 0) ? "+" : "-", 1, buf);
	if (exp > -9 && exp < -9 && frmt->fl == 10)
		PRINT("0", 1, buf);
//	if (exponent == 0)
//		buffered_print("0", 1, buffer);
//  else
	print_itoa_base(exp, frmt, buf);
}

void	set_width_ae(long double d, uint64_t integer, t_format *frmt)
{
	if ((d < 0) || (frmt->fl & MINUS) || (frmt->fl & SPACE))
		frmt->width -= 1;
	frmt->width = frmt->width - length_base(integer, frmt->base) - ft_strlen(frmt->prefix);
	frmt->width -= (frmt->prec == 0) ? 0 : frmt->prec + 1;
}

void	print_ae(t_format *frmt, long double d, t_buffer *buf)
{
	uint64_t	integer;
	int64_t 	exp;
	uintmax_t 	n;
	long double	fraction;

	integer = (uint64_t)d;
	fraction = d - integer;
	set_exp(frmt, &exp, d);
	(!(frmt->fl & PRECISION)) ? frmt->prec = 6 : 0;
	set_width_ae(d, integer, frmt);
	print_sign(d, frmt, buf);
	n = (frmt->prec == 0) ? ft_roundl(integer + fraction) : integer;
	print_itoa_base(n, frmt, buf);
	if (frmt->fl & SHARP || frmt->prec > 0)
		print_fraction(fraction, frmt, buf);
	n = ft_imaxabs(exp);
	print_exp(exp, n, frmt, buf);
	if (frmt->fl & MINUS)
		padding(" ", frmt->width, buf);
}

