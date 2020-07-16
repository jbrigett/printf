/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrigett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 18:55:09 by jbrigett          #+#    #+#             */
/*   Updated: 2020/07/16 19:20:48 by jbrigett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_s(t_format *frmt)
{
	char		*s;
	int			i;
	int			len;

	i = 0;
	s = va_arg(frmt->ap, char *);
	if (frmt->prec > -1 && s)
		s = ft_strndup(s, frmt->prec);
	else if (frmt->prec == -1 && s)
		s = ft_strdup(s);
	else if (frmt->prec > -1 && !s)
		s = ft_strndup("(null)", frmt->prec);
	else if (frmt->prec == -1 && !s)
		s = ft_strdup("(null)");
	len = ft_strlen(s);
	frmt->len += len;
	if (!(frmt->fl & MINUS))
		padding((frmt->fl & ZERO) ? "0" : " ", frmt->width - len, buf);
	ft_putstr(s);
	if (frmt->fl & MINUS)
		padding(" ", frmt->width - len, buffer);
	free(s);
}
