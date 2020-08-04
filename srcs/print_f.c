/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrigett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 18:54:40 by jbrigett          #+#    #+#             */
/*   Updated: 2020/07/22 18:27:34 by jbrigett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		print_sign(t_double *d, t_format *frmt)
{
	if (!(frmt->fl & MINUS) && !(frmt->fl & ZERO) && frmt->width > 0)
		padding(frmt, ' ', frmt->width - frmt->prec - length_base(d->integer, 10));
	if (d->n < 0)
		print_all(frmt, "-", 1);
	else if (frmt->fl & PLUS)
		print_all(frmt, "+", 1);
	else if (frmt->fl & SPACE)
		print_all(frmt, " ", 1);
	if ((d->n != 0.0) && frmt->fl & SHARP)
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

void		print_fraction(t_double *t, t_format *frmt)
{
	print_all(frmt, ".", 1);
	if (t->fraction == 0.0)
	{
		while (frmt->prec--)
			print_all(frmt, "0", 1);
		return ;
	}
	else if (frmt->prec > 0)
	{
		while (frmt->len--)
			print_all(frmt, "0", 1);
		while (frmt->prec--)
			t->fraction *= frmt->base;
		print_itoa_base(ft_roundl(t->fraction), frmt);
	}
}

void		set_parts(t_format *frmt, t_double *t)
{
	intmax_t	fr;
	int32_t		tmp;

	t->integer = (uint64_t)ft_fabsl(t->n);
	(frmt->prec == 0) ? (t->integer = ft_imaxabs(ft_roundl(t->n))) : 0;
	t->fraction = ft_fabsl(t->n) - t->integer;
	tmp = frmt->prec;
	if (frmt->prec && t->fraction != 0.0)
	{
		while (tmp--)
			t->fraction *= frmt->base;
		fr = ft_roundl(t->fraction);
		tmp = (int32_t)length_base(fr, 10);
		frmt->len = frmt->prec - tmp;
		if (tmp > frmt->prec)
		{
			t->fraction = 0.0;
			t->integer += 1;
		}
		else
			t->fraction = ft_fabsl(t->n) - t->integer;
	}
}

void		print_f(t_format *frmt, long double d)
{
	t_double	*t;
	int32_t		tmp;

	if (!(t = (t_double*)malloc(sizeof(t_double))))
		return ;
	if (check_spec_val(frmt, d))
		return ;
	t->n = d;
	set_parts(frmt, t);
	if ((d < 0) || (frmt->fl & PLUS) || (frmt->fl & SPACE))
		frmt->width -= 1;
	set_width_ae(t->integer, frmt);
	if (!(frmt->fl & MINUS) && !(frmt->fl & ZERO) && frmt->width > 0)
		padding(frmt, ' ', frmt->width - frmt->len);
	print_sign(t, frmt);
	tmp = frmt->len;
	frmt->len = (t->integer == 0) ? 1 : length_base(t->integer, 10);
	print_itoa_base(t->integer, frmt);
	frmt->len = tmp;
	if (frmt->prec > 0)
		print_fraction(t, frmt);
	if (frmt->fl & MINUS)
		padding(frmt, ' ',  frmt->width - frmt->prec - length_base(t->integer, 10));
}
