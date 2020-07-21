#include "ft_printf.h"

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
