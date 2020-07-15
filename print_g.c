#include "ft_printf.h"

int32_t compare_fe(long double d, t_format *frmt)
{
	long double	fraction;
	int64_t		exp;
	size_t 		len;
	int64_t		tmp;

	set_exp(frmt, &exp, d);
	len = length_base((uintmax_t)ft_fabsl(d), 10);
	if ((intmax_t)len > frmt->prec || exp <= -4)
	{
		frmt->prec -= (intmax_t)len;
		return (1);
	}
	frmt->prec += (exp < 0) ? ft_imaxabs(exp) : 0;
	tmp = len;
	fraction = d - (intmax_t)d;
	while (fraction < 0)
	{
		fraction *= 10;
		fraction -= (int64_t)fraction;
		++tmp;
	}
	frmt->prec = (tmp < frmt->prec) ? tmp : frmt->prec - (intmax_t)len;
	return (0);
}

void	print_g(long double d, t_format *frmt, t_buffer *buf)
{
	int64_t	precision;

	if (compare_fe(d, frmt))
		print_ae(frmt, d, buf);
	else
		print_f(frmt, d, buf);
}