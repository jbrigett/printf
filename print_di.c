#include "ft_printf.h"

void	add_sign(intmax_t n, t_format *frmt, char *str)
{
	if (n < 0)
		*str = '-';
	else if (frmt->fl & PLUS)
		*str = '+';
	else if (frmt->fl & SPACE)
		*str = ' ';
}

void	set_width(intmax_t n, t_format *frmt)
{
	int fl;

	frmt->to_print = 0;
	fl = (n < 0 || frmt->fl & PLUS || frmt->fl & SPACE) ? 1 : 0;
	if (fl && frmt->fl & ZERO)
		--frmt->prec;
	while (n)
	{
		n /= 10;
		++frmt->to_print;
	}
	frmt->to_print += ft_max(frmt->to_print, frmt->prec);
	frmt->to_print += fl;
}

void	settings_d(intmax_t n, t_format *frmt, t_buffer *buf)
{
	char str[22];

	if (frmt->fl & PRECISION) //игнорим для dioux
		frmt->fl &= ~ZERO;
	if (frmt->fl & ZERO)
		frmt->prec = frmt->width;
	set_width(n, frmt);
	if (!(frmt->fl & MINUS) && !(frmt->fl & ZERO))
		padding(" ", frmt->width - frmt->to_print, buf);
	add_sign(n, frmt, str);
	ft_itoa_base(frmt, ft_imaxabs(n), str, 0, 0);
	PRINT(str, frmt->to_print, buf);
	if (frmt->fl & MINUS)
		padding(" ", frmt->width - frmt->to_print, buf);
}

void	print_di(t_format *frmt, t_buffer *buf)
{
	intmax_t n;

	if (frmt->fl & LLONG)
		n =  (intmax_t)va_arg(frmt->ap, long long);
	else if (frmt->fl & LONG)
		n =  (intmax_t)va_arg(frmt->ap, long);
	else if (frmt->fl & SHORT)
		n = (short)va_arg(frmt->ap, int);
	else if (frmt->fl & SSHORT)
		n = (char)va_arg(frmt->ap, int);
	else if (frmt->fl & SIZE_T)
		n = (size_t)va_arg(frmt->ap, size_t);
	else if (frmt->fl & INTMAX)
		n = (intmax_t)va_arg(frmt->ap, intmax_t);
	else
		n = (int)va_arg(frmt->ap, int);
	(frmt->fl & ZERO) ? frmt->prec = frmt->width : 0;
	settings_d(n, frmt, buf);
}