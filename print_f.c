/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrigett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 18:54:40 by jbrigett          #+#    #+#             */
/*   Updated: 2020/07/16 19:18:59 by jbrigett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_sign(long double d, t_format *frmt, t_buffer *buf)
{
	if (!(frmt->fl & MINUS) && !(frmt->fl & ZERO))
		padding(" ", frmt->width - frmt->to_print, buf);
	if (d < 0)
		PRINT("-", 1, buf);
	PRINT(frmt->prefix, ft_strlen(frmt->prefix), buf);
}

int			check_spec_val(t_format *frmt, long double n, t_buffer *buf)
{
	uint64_t	integ;
	double		dn;
	int			fl;

	dn = (double)n;
	integ = *(uint64_t*)&dn;
	fl = frmt->fl & UPPER ? 1 : 0;
	if (((integ >> 52) & LD_MASK) == LD_CHECK)
	{
		PRINT(integ & LD_FRAC ? (fl ? "INF" : "inf") : (fl ? "NAN" : "nan"));
		return (1);
	}
	else if (((integ >> 52) & LD_MASK) == LD_MASK)
	{
		PRINT(integ & LD_FRAC ? (fl ? "-INF" : "-inf") : (fl ? "-NAN" : "-nan"));
		return (1);
	}
	return (0);
}

void		print_fraction(long double fraction, t_format *frmt, t_buffer *buf)
{
	uintmax_t abs_f;

	PRINT(".", 1, buf);
	if (fraction == 0.0)
		while (frmt->prec--)
			PRINT("0", 1, buf);
	if (frmt->prec)
	{
		while (fraction < 0.1 && frmt->prec--)
		{
			PRINT("0", 1, buf);
			fraction *= frmt->base;
		}
		while (frmt->prec--)
			fraction *= frmt->base;
		abs_f = ft_roundl(fraction);
		print_itoa_base(abs_f, frmt, buf);
	}
}

void		print_f(t_format *frmt, long double d, t_buffer *buf)
{
	uint64_t	integer;
	uintmax_t	n;
	long double	fraction;

	if (check_spec_val(frmt, d, buf))
		return ;
	integer = (uint64_t)ft_fabsl(d);
	fraction = ft_fabsl(d) - integer;
	if ((d < 0) || (frmt->fl & MINUS) || (frmt->fl & SPACE))
		frmt->width -= 1;
	frmt->width = frmt->width - length_base(integer, frmt->base) -
		ft_strlen(frmt->prefix);
	frmt->width -= (frmt->prec == 0) ? 0 : frmt->prec + 1;
	print_sign(d, frmt, buf);
	n = (frmt->prec == 0) ? ft_imaxabs(ft_roundl(d)) : integer;
	print_itoa_base(n, frmt, buf);
	if (frmt->fl & SHARP || frmt->prec > 0)
		print_fraction(fraction, frmt, buf);
	if (frmt->fl & MINUS)
		padding(" ", frmt->width, buf);
}
