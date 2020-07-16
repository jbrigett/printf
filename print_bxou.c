/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bxou.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrigett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 18:53:33 by jbrigett          #+#    #+#             */
/*   Updated: 2020/07/16 19:11:47 by jbrigett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_prefix(uintmax_t n, t_format *frmt, t_buffer *buf)
{
	char	*pref;

	if (frmt->base == 16)
		pref = (frmt->fl & UPPER) ? "0X" : "0x";
	if (frmt->base == 2)
		pref = (frmt->fl & UPPER) ? "0B" : "0b";
	if (((n != 0) || frmt->fl & POINTER || frmt->base == 8) && frmt->fl & SHARP)
		PRINT(pref, ft_strlen(pref), buf);
}

void	set_width_base(t_format *frmt, uintmax_t n)
{
	uintmax_t	tmp;

	frmt->to_print = 0;
	tmp = n;
	while (tmp > 0)
	{
		tmp /= frmt->base;
		++frmt->to_print;
	}
	if (frmt->base == 8 && frmt->fl & SHARP)
		if (frmt->to_print >= frmt->prec)
			frmt->prec = frmt->to_print + 1;
	frmt->to_print = ft_max(frmt->to_print, frmt->prec);
	if (frmt->base == 8 && frmt->fl & SHARP && !n &&
			frmt->fl & PRECISION && frmt->prec <= 0)
		++frmt->to_print;
	if (frmt->base != 8 && frmt->fl & SHARP && !(frmt->fl & ZERO))
		frmt->width -= 2;
}

void	settings_bxou(uintmax_t n, t_format *frmt, t_buffer *buf)
{
	char	str[21];

	if (frmt->fl & PRECISION)
		frmt->fl &= ~ZERO;
	set_width_base(frmt, n);
	if (!(frmt->fl & MINUS) && !(frmt->fl & ZERO))
		padding(' ', frmt->width - frmt->to_print);
	print_prefix(n, frmt, buf);
	if (!(frmt->fl & MINUS) && frmt->fl & ZERO && frmt->fl & PRECISION)
		padding("0", frmt->width - frmt->to_print, buf);
	print_itoa_base(n, frmt, buf);
	PRINT(str, frmt->to_print, buf);
	if (frmt->fl & MINUS)
		padding(" ", frmt->width - frmt->to_print, buf);
}

/*
 ** проверить приведение типов
 */
void	dprint_bxou(t_format *frmt, t_buffer *buf)
{
	uintmax_t n;

	if (frmt->fl & LLONG)
		n = (intmax_t)va_arg(frmt->ap, unsigned long long);
	else if (frmt->fl & LONG)
		n = (intmax_t)va_arg(frmt->ap, unsigned long);
	else if (frmt->fl & SHORT)
		n = (short)va_arg(frmt->ap, unsigned int);
	else if (frmt->fl & SSHORT)
		n = (char)va_arg(frmt->ap, unsigned int);
	else if (frmt->fl & SIZE_T)
		n = (size_t)va_arg(frmt->ap, size_t);
	else if (frmt->fl & INTMAX)
		n = (intmax_t)va_arg(frmt->ap, uintmax_t);
	else
		n = (int)va_arg(frmt->ap, unsigned int);
	(frmt->fl & ZERO) ? frmt->prec = frmt->width : 0;
	settings_bxou(n, frmt, buf);
}
