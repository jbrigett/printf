/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrigett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 18:50:44 by jbrigett          #+#    #+#             */
/*   Updated: 2020/07/16 19:01:01 by jbrigett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double	ft_fabsl(long double d)
{
	uintmax_t	res;

	res = *(uintmax_t*)&d;
	res &= LD_MASK_LONG;
	return (*(long double*)&res);
}

uintmax_t	ft_imaxabs(intmax_t n)
{
	intmax_t mask;

	mask = (n >> (sizeof(n) * 8 - 1));
	n = (uintmax_t)((n + mask) ^ mask);
	return (n);
}

intmax_t	ft_roundl(long double d)
{
	intmax_t	integ;
	long double	fract;

	integ = (intmax_t)d;
	fract = d - integ;
	if (d >= 0)
		return ((fract < 0.5) ? integ : integ + 1);
	else
		return ((fract > 0.5) ? integ : integ - 1);
}
