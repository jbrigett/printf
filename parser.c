/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrigett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 18:52:41 by jbrigett          #+#    #+#             */
/*   Updated: 2020/07/16 19:04:58 by jbrigett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	dollar_parser(char **str, t_format *frmt)
{
	int		nbr;
	char	*tmp;

	if (!ft_isdigit(**str))
		return ;
	nbr = 0;
	tmp = *str;
	while (ft_isdigit(**str))
	{
		nbr = nbr * 10 + (**str - '0');
		++(*str);
	}
	if (**str != '$')
	{
		*str = tmp;
		return ;
	}
	++(*str);
	frmt->order = nbr;
}

void	flag_and_width(char **str, t_format *frmt)
{
	int n;

	while ((n = ft_strchr_index("+-#0 '", **str)) >= 0 && ++(*str))
		frmt->fl |= (1 << n);
	frmt->fl &= (frmt->fl & PLUS) ? ~SPACE : 0;
	if (**str == '*')
	{
		n = (int)va_arg(frmt->ap, int);
		(n < 0) ? (frmt->fl |= MINUS) : (frmt->fl &= ~MINUS);
		n = (n < 0) ? -n : n;
		frmt->width = n;
		++(*str);
	}
	else if ((frmt->width = ft_max(ft_atoi(*str), 1)))
		while (ft_isdigit(**str))
			++(*str);
//	frmt->fl &= (frmt->fl & MINUS && !(frmt->fl & WILDCARD)) ? ~ZERO : 0;
}

void	precision_parser(char **str, t_format *frmt)
{
	if (**str == '.')
	{
		frmt->fl |= PRECISION;
		++(*str);
		if (**str == '*')
		{
			if ((frmt->prec = (int)va_arg(frmt->ap, int)) < 0)
				frmt->fl &= ~PRECISION;
			++(*str);
		}
		else
		{
			frmt->prec = ft_max(ft_atoi(*str), 0);
			while (ft_isdigit(**str))
				++(*str);
		}
	}
}

void	length_parser(char **str, t_format *frmt)
{
	if (**str == 'h')
		frmt->fl |= (**str == 'h' && ++(*str)) ? SSHORT : SHORT;
	else if (**str == 'l')
		frmt->fl |= (**str == 'l' && ++(*str)) ? LLONG : LONG;
	else if (**str == 'j')
		frmt->fl |= INTMAX;
	else if (**str == 'z')
		frmt->fl |= SIZE_T;
	else if (**str == 'L')
		frmt->fl |= LLONG;
	++(*str);
}

void	parser( char **str, t_format *frmt)
{
	reinit_format(frmt);
	dollar_parser(str, frmt);
	flag_and_width(str, frmt);
	precision_parser(str, frmt);
	length_parser(str, frmt);
	spec_parser(str, frmt);
}
