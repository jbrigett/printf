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

void	set_exp(uint64_t *integer, long double *fraction, t_format *frmt, int64_t *exp, long double n)
{
	*integer = 0;
	*fraction = 0.0;
	*exp = 0;
	if (n == 0)
		return ;
	if (n < 1)
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
	*integer = (uint64_t)n;
	*fraction = n - *integer;
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
	print_itoa_base(exp, frmt);
}

void	set_width_ae(uint64_t integer, t_format *frmt)
{
	frmt->width -= length_base(integer, frmt->base);
	frmt->width	-= ft_strlen(frmt->pref);
	frmt->width -= (frmt->prec == 0) ? 0 : frmt->prec + 1;
	//printf(" %llu  ", integer);

}
/*
void	print_ae(t_format *frmt, long double d)
{
	uint64_t	integer;
	int64_t		exp;
	uintmax_t	n;
	long double	fraction;

	set_exp(&integer, &fraction, frmt, &exp, d);
	(!(frmt->fl & PRECISION)) ? frmt->prec = 6 : 0;
	if ((d < 0) || (frmt->fl & MINUS) || (frmt->fl & SPACE))
		frmt->width -= 1;
	set_width_ae(integer, frmt);
	print_sign(d, frmt);
	n = (frmt->prec == 0) ? ft_roundl(integer + fraction) : integer;
	print_itoa_base(n, frmt);
	if (frmt->fl & SHARP || frmt->prec > 0)
		print_fraction(fraction, frmt);
	n = ft_imaxabs(exp);
	print_exp(exp, frmt);
	if (frmt->fl & MINUS)
		padding(frmt, ' ', frmt->width);
}

*/
void	print_ae(t_format *frmt, long double d)
{
	/*
	uint64_t	integer;
	long double	fraction;
	int64_t		exp;

	integer = (uint64_t)ft_fabsl(d);
	fraction = d - integer;
	frmt->base = 1;
	set_exp(frmt, &exp, d);
	(!(frmt->fl & PRECISION)) ? frmt->prec = 6 : 0;
	//frmt->width -= length_base(integer, frmt->base);
	frmt->width	-= ft_strlen(frmt->pref);
	frmt->width -= (frmt->prec == 0) ? 0 : frmt->prec + 1;
	print_sign(d, frmt);
//	if (d < 0)
	printf("%Lf  %llu   %lld", fraction, integer, exp); */

	uint64_t	integer;
	uintmax_t	n;
	long double	fraction;
//

//	set_exp(&integer, &fraction, frmt, &exp, d);
	if ((d < 0) || (frmt->fl & MINUS) || (frmt->fl & SPACE))
		frmt->width -= 1;
	frmt->width -= (length_base(integer, frmt->base) + ft_strlen(frmt->pref));
	frmt->width -= (frmt->prec == 0) ? 0 : frmt->prec + 1;
	print_sign(d, frmt);
	n = (frmt->prec == 0) ? ft_roundl(integer + fraction) : integer;
	print_itoa_base(n, frmt);
	if (frmt->fl & SHARP || frmt->prec > 0)
		print_fraction(fraction, frmt);
	if (frmt->fl & MINUS)
		padding(frmt, ' ', frmt->width);
}
