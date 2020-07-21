/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrigett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 15:02:18 by jbrigett          #+#    #+#             */
/*   Updated: 2020/07/21 15:02:23 by jbrigett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_all(t_format *frmt, char *str, int len)
{
	int i;

	i = 0;
	frmt->to_print += len;
	while (i < len)
	{
		write(frmt->fd, &(*str), len);
		str++;
		i++;
	}
}

void	padding(t_format *frmt, char c, int len)
{
	int i;

	i = 0;
	frmt->to_print += len;
	while (i < len)
	{
		write(frmt->fd, &c, len);
		i++;
	}
}
