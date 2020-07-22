/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrigett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 18:50:44 by jbrigett          #+#    #+#             */
/*   Updated: 2020/07/21 15:00:50 by jbrigett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

long double	ft_fabsl(long double d)
{
	/*uintmax_t	res;

	res = *(uintmax_t*)&d;
	res &= LD_MASK_LONG;
	return (*(long double*)&res); */

	return ((d < 0) ? -d : d);
}

uintmax_t	ft_imaxabs(intmax_t d)
{
	/*intmax_t mask;

	mask = (n >> (sizeof(n) * 8 - 1));
	n = (uintmax_t)((n + mask) ^ mask);
	return (n);*/

	return ((d < 0) ? -d : d);

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

size_t		length_base(uintmax_t n, int8_t base)
{
	size_t	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n > 0)
	{
		n /= base;
		len++;
	}
	return (len);
}
