/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_spec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrigett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 18:53:02 by jbrigett          #+#    #+#             */
/*   Updated: 2020/07/16 19:05:52 by jbrigett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	base_parser(t_format *frmt)
{
	if (ft_memchr("b", frmt->spec, 1))
		frmt->base = 2;
	if (ft_memchr("o", frmt->spec, 1))
		frmt->base = 8;
	if (ft_memchr("diufge", frmt->spec, 6))
		frmt->base = 10;
	if (ft_memchr("xa", frmt->spec, 2))
		frmt->base = 16;
	else
		frmt->base = 0;
}

void	mode_parser(t_format *frmt)
{
	if (ft_memchr("di", frmt->spec, 2))
		print_di(frmt);
	else if (ft_memchr("boux", frmt->spec, 4))
		print_bxou(frmt);
	else if (ft_memchr("afge", frmt->spec, 4))
		print_aefg(frmt);
	else if (frmt->spec == 's' && frmt->fl & LONG)
		print_ws(frmt);
	else if (frmt->spec == 's')
		print_s(frmt);
	else if (frmt->spec == 'c')
		print_c(frmt);
	else if (frmt->spec == 'n')
		print_n(frmt);
	else if (frmt->spec == 'p')
		print_p(frmt);
	else if (frmt->spec == '%')
		print_percent(frmt);
	else
		cs_not_found(frmt);
}

void	set_upper_flag(char c, t_format *format)
{
	if (ft_strchr("DCOSU", c) != NULL)
	{
		format->fl |= LONG;
		format->spec += 32;
	}
	else if (ft_strchr("ABFEGX", c) != NULL)
	{
		format->fl |= UPPER;
		format->spec += 32;
	}
	else
		format->spec = c;
}

void	spec_parser(char **str, t_format *frmt)
{
	if (!*str)
		return ;
	if (ft_isupper(**str))
		set_upper_flag(**str, frmt);
	else
		frmt->spec = **str;
	++(*str);
	base_parser(frmt);
	mode_parser(frmt);
}
