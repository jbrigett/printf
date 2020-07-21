/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrigett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 17:26:51 by jbrigett          #+#    #+#             */
/*   Updated: 2020/07/21 17:36:36 by jbrigett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (s[len])
	{
		len++;
	}
	return (len);
}

char	*ft_strdup(const char *s1)
{
	char *tmp;

	if (ft_strlen(s1) + 1 == 0)
		return (NULL);
	tmp = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!tmp)
		return (NULL);
	ft_strcpy(tmp, s1);
	return (tmp);
}

int		ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int		ft_atoi(const char *str)
{
	long long	tmp;
	long long	res;
	int			signe;

	while (ft_isspace(*str))
		str++;
	signe = (*str == '-') ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	res = 0;
	while (ft_isdigit(*str))
	{
		tmp = res;
		res = res * 10 + (*str - '0');
		if (tmp != (res - (*str - '0')) / 10 || res < 0)
			return (-1 * (signe + 1) / 2);
		str++;
	}
	return (signe < 0 ? -res : res);
}

int		ft_isspace(int c)
{
	c = (unsigned char)c;
	if (c == ' ' || c == '\t' || c == '\n' ||
			c == '\v' || c == '\r' || c == '\f')
		return (1);
	return (0);
}
