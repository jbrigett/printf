#include "ft_printf.h"

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
		frmt->func = &print_di;
	if (ft_memchr("boux", frmt->spec, 4))
		frmt->func = &print_bxou;
	if (ft_memchr("afge", frmt->spec, 4))
		frmt->func = &print_aefg;
	if (frmt->spec == 's')
		frmt->func = &pf_ft_putstr;
	if (frmt->spec == 'c')
		frmt->func = &print_c;
	if (frmt->spec == 'n')
		frmt->func = &pf_printlen;
	if (frmt->spec == 'm')
		frmt->func = &pf_puterror;
	if (frmt->spec== 'p')
		frmt->func = &print_pointer_address;
	else
		frmt->func = &cs_not_found;
}

static void	set_upper_flag(char c, t_format *format)
{
	if (ft_strchr("DCOSU", c) != NULL)
	{
		format->fl |= LONG;
		format->spec = c + 32;
	}
	else if (ft_strchr("ABFEGX", c) != NULL)
	{
		format->fl |= UPPER;
		format->spec = c + 32;
	}
	else
		format->spec = c;
}

void		spec_parser(char *string, t_format *format)
{
	if (!*string)
		return ;
	if (ft_isupper(*string))
		set_upper_flag(string, format);
	else
		format->spec = *string;
	string += 1;
	base_parser(format);
	mode_parser(format);
}