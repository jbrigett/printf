#include "ft_printf.h"

void	ft_strup(char *str)
{
	while (*str)
	{
		if (*str >= 97 &&  *str <=122)
			*str = *str - 32;
	}
}

void	ft_itoa_base(t_format *format, uintmax_t n, char *str, int	mode, size_t len)
{
	char	*print;
	size_t		tmp;

	print = "0123456789abcdef";
	format->fl & UPPER ? ft_strup(&print) : 0;
	tmp = (mode == 1) ? format->to_print : len;
	while (tmp--)
	{
		str[tmp] = print[n % format->base];
		n /= format->base;
	}
}


void	print_itoa_base(uintmax_t n, t_format *frmt, t_buffer *buf)
{
	uintmax_t	tmp;
	size_t		len;
	char		nb_str[33];

	len = 1;
	tmp = 33;
	while (tmp-- > 0)
		nb_str[tmp] = 0;
	tmp = n;
	while ((tmp /= frmt->base) > 0)
		++len;
	if ((n == 0) && (frmt->fl & PRECISION) && (frmt->prec == 0))
		nb_str[0] = '\0';
	else if (n == 0)
		nb_str[0] = '0';
	else
		ft_itoa_base(frmt, n, nb_str, 1, len);
	PRINT(nb_str, ft_strlen(nb_str), buf);
}
