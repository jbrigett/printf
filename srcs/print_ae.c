/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ae.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrigett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 18:53:14 by jbrigett          #+#    #+#             */
/*   Updated: 2020/07/21 15:04:46 by jbrigett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	set_exp(t_double *doub, t_format *frmt)
{
	doub->fraction = 0.0;
	doub->integer = 0;
	doub->exp = 0;
	if (doub->n != 0)
	{
		if (doub->n < 1)
			while (doub->n < 1) {
				doub->exp -= 1;
				doub->n *= (frmt->base == 10) ? frmt->base : 2;
			}
		else if (doub->n >= 1)
			while (doub->n > ((frmt->base == 10) ? frmt->base - 1 : 2))
			{
				doub->exp += 1;
				doub->n /= (frmt->base == 10) ? frmt->base : 2;
			}
		doub->integer = (uint64_t)doub->n;
		doub->fraction = doub->n - doub->integer;
	}
}

void	print_exp(int64_t exp, t_format *frmt)
{
	if (frmt->base == 16)
		print_all(frmt, (frmt->fl & UPPER) ? "P" : "p", 1);
	else
		print_all(frmt, (frmt->fl & UPPER) ? "E" : "e", 1);
	print_all(frmt, (exp >= 0) ? "+" : "-", 1);
	if (exp > -9 && exp < 9 && frmt->base == 10)
		print_all(frmt, "0", 1);
	print_itoa_base(ft_imaxabs(exp), frmt);
}

void	set_width_ae(uint64_t integer, t_format *frmt)
{
	frmt->width -= length_base(integer, frmt->base);
	frmt->width	-= ft_strlen(frmt->pref);
	frmt->width -= (frmt->prec == 0) ? 0 : frmt->prec + 1;
}

void	print_ae(t_format *frmt, long double d)
{
	uintmax_t	n;
	t_double    *doub;

	if (!(doub = (t_double*)malloc(sizeof(t_double))))
		return ;
	doub->n = d;
	set_exp(doub, frmt);
	(!(frmt->fl & PRECISION)) ? frmt->prec = 6 : 0;
	if ((d < 0) || (frmt->fl & MINUS) || (frmt->fl & SPACE))
		frmt->width -= 1;
	set_width_ae(doub->integer, frmt);
	print_sign(d, frmt);
	n = (frmt->prec == 0) ? ft_roundl(doub->integer + doub->fraction) : doub->integer;
	print_itoa_base(n, frmt);
	if (frmt->fl & SHARP || frmt->prec > 0)
		print_fraction(doub->fraction, frmt);
	print_exp(doub->exp, frmt);
	if (frmt->fl & MINUS)
		padding(frmt, ' ', frmt->width);
}