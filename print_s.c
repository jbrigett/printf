#include "ft_printf.h"


size_t	ft_wcharlen(wint_t c, t_format *frmt)
{
	if (c <= 0x7F)
		return (1);
	if (c >= 0x80 && c <= 0x7FF)
		return (2);
	if (c >= 0x80 && c <= 0xFFFF)
		return (3);
	if (c >= 0x10000 && c <= 0x1FFFFF)
		return (4);
}

void		print_wstring(wchar_t *wstr, t_format *frmt, int64_t strlen)
{
	while ((strlen -= ft_wcharlen(*wstr, frmt)) >= 0)
		print_wchar(*wstr++, frmt);
}

int64_t	wslen(char *str, wchar_t *wstr, t_format *frmt)
{
	intmax_t	len;
	intmax_t	strlen;

	strlen = 0;
	len = frmt->prec;
	if (frmt->fl & LONG) {
		while (*wstr != L'\0') {
			if (frmt->fl & PRECISION && ft_wcharlen(*wstr, frmt) > (size_t) len)
				break;
			strlen += ft_wcharlen(*wstr, frmt);
			len -= ft_wcharlen(*wstr, frmt);
			++wstr;
		}
		len = strlen;
	}
	else
		len = (frmt->fl & PRECISION) ? ft_min(ft_strlen(str), frmt->prec) : ft_strlen(str);
	return (len);
}

void	print_s(t_format *frmt, va_list *app, t_buffer *buffer)
{
	char		*str;
	wchar_t		*wstr;

	str = "";
	wstr = L"";
	if (frmt->fl & LONG)
		wstr = va_arg(*app, wchar_t*);
	else
		str = va_arg(*app, char*);
	frmt->len = wslen(str, wstr, frmt);
	if (!(frmt->fl & MINUS))
		padding((frmt->fl & ZERO) ? "0" : " ", frmt->width - frmt->len, buffer);
	if (frmt->fl & LONG && wstr != NULL)
		print_wstring(wstr, frmt, frmt->len);
	else if (str != NULL)
		ft_putstr(str);
	if (frmt->prec > -1 && !str)
		ft_putstr(ft_strndup("(null)", frmt->prec));
	else if (frmt->prec == -1 && !str)
		ft_putstr(ft_strdup("(null)"));
	if (frmt->fl & MINUS)
		padding(" ", frmt->width - frmt->len, buffer);
}

