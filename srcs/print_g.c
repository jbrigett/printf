/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_g.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrigett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 18:54:50 by jbrigett          #+#    #+#             */
/*   Updated: 2020/07/16 19:20:15 by jbrigett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int32_t	compare_fe(long double d, t_format *frmt)
{
	long double	fraction;
	int64_t		exp;
	size_t		len;
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

void	print_g(t_format *frmt, long double d)
{
	if (compare_fe(d, frmt))
		print_ae(frmt, d);
	else
		print_f(frmt, d);
}
