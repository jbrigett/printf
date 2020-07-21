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

#include "../includes/ft_printf.h"

void		print_sign(long double d, t_format *frmt)
{
	if (!(frmt->fl & MINUS) && !(frmt->fl & ZERO))
		padding(frmt, ' ', frmt->width - frmt->len);
	if (d < 0)
		print_all(frmt, "-", 1);
	print_all(frmt, frmt->pref, ft_strlen(frmt->pref));
}

int			check_spec_val(t_format *frmt, long double n)
{
	uint64_t	integ;
	double		dn;

	dn = (double)n;
	integ = *(uint64_t*)&dn;
	if (((integ >> 52) & LD_MASK) == LD_CHECK)
	{
		if (integ & LD_FRAC)
			print_all(frmt, (frmt->fl & UPPER) ? "INF" : "inf", 3);
		else
			print_all(frmt, (frmt->fl & UPPER) ? "NAN" : "nan", 3);
		return (1);
	}
	else if (((integ >> 52) & LD_MASK) == LD_MASK)
	{
		if (integ & LD_FRAC)
			print_all(frmt, (frmt->fl & UPPER) ? "-INF" : "inf", 4);
		else
			print_all(frmt, (frmt->fl & UPPER) ? "-NAN" : "-nan", 4);
		return (1);
	}
	return (0);
}

void		print_fraction(long double fraction, t_format *frmt)
{
	uintmax_t abs_f;

	print_all(frmt, ".", 1);
	if (fraction == 0.0)
		while (frmt->prec--)
			print_all(frmt, "0", 1);
	if (frmt->prec)
	{
		while (fraction < 0.1 && frmt->prec--)
		{
			print_all(frmt, "0", 1);
			fraction *= frmt->base;
		}
		while (frmt->prec--)
			fraction *= frmt->base;
		abs_f = ft_roundl(fraction);
		print_itoa_base(abs_f, frmt);
	}
}

void		print_f(t_format *frmt, long double d)
{
	uint64_t	integer;
	uintmax_t	n;
	long double	fraction;

	if (check_spec_val(frmt, d))
		return ;
	integer = (uint64_t)ft_fabsl(d);
	fraction = ft_fabsl(d) - integer;
	if ((d < 0) || (frmt->fl & MINUS) || (frmt->fl & SPACE))
		frmt->width -= 1;
	frmt->width -= (length_base(integer, frmt->base) + ft_strlen(frmt->pref));
	frmt->width -= (frmt->prec == 0) ? 0 : frmt->prec + 1;
	print_sign(d, frmt);
	n = (frmt->prec == 0) ? ft_imaxabs(ft_roundl(d)) : integer;
	print_itoa_base(n, frmt);
	if (frmt->fl & SHARP || frmt->prec > 0)
		print_fraction(fraction, frmt);
	if (frmt->fl & MINUS)
		padding(frmt, ' ', frmt->width);
}