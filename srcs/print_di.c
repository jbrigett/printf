/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrigett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 18:54:32 by jbrigett          #+#    #+#             */
/*   Updated: 2020/07/16 19:16:11 by jbrigett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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

	frmt->len = 0;
	fl = (n < 0 || frmt->fl & PLUS || frmt->fl & SPACE) ? 1 : 0;
	if (fl && frmt->fl & ZERO)
		--frmt->prec;
	n = ft_imaxabs(n);
	while (n)
	{
		n /= 10;
		++frmt->len;
	}
	frmt->len = ft_max(frmt->len, frmt->prec) + fl;
}

void	settings_d(intmax_t n, t_format *frmt)
{
	char str[22];

	if (frmt->fl & PRECISION)
		frmt->fl &= ~ZERO;
	if (frmt->fl & ZERO)
		frmt->prec = frmt->width;
	set_width(n, frmt);
	if (!(frmt->fl & MINUS) && !(frmt->fl & ZERO))
		padding(frmt, ' ', frmt->width - frmt->len);
	itoa_base(frmt, ft_imaxabs(n), str);
	add_sign(n, frmt, str);
	print_all(frmt, str, frmt->len);
	if (frmt->fl & MINUS)
		padding(frmt, ' ', frmt->width - frmt->len);
}

void	print_di(t_format *frmt)
{
	intmax_t n;

	if (frmt->fl & LLONG)
		n = (long long)va_arg(frmt->ap, long long);
	else if (frmt->fl & LONG)
		n = (long)va_arg(frmt->ap, long);
	else if (frmt->fl & SHORT)
		n = (short)va_arg(frmt->ap, int);
	else if (frmt->fl & SSHORT)
		n = (char)va_arg(frmt->ap, int);
	else if (frmt->fl & SIZE_T)
		n = (size_t)va_arg(frmt->ap, size_t);
	else if (frmt->fl & INTMAX)
		n = (intmax_t)va_arg(frmt->ap, intmax_t);
//	else if (frmt->fl & PTRDIFF)
//		n = (ptrdiff_t)va_arg(*app, ptrdiff_t);
	else
		n = (int)va_arg(frmt->ap, int);
	(frmt->fl & ZERO) ? frmt->prec = frmt->width : 0;
	settings_d(n, frmt);
}
