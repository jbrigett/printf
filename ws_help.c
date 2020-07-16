#include "ft_printf.h"

static wchar_t	*wstrndup(wchar_t *s1, size_t n)
{
	wchar_t	*s2;
	size_t	i;

	i = 0;
	if (!(s2 = (wchar_t *)malloc(sizeof(wchar_t) * n + 1)))
		exit(-1);
	while (s1[i] && i < n)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

static wchar_t	*wstrdup(wchar_t *str)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	return (wstrndup(str, len));
}

static t_tab	*do_null(t_tab *tab)
{
	wchar_t		*s;
	int			i;

	i = 0;
	s = wstrdup(L"(null)");
	if (tab->precision > -1)
	{
		while (s[i] && tab->precision-- > 0)
			display_wchar(s[i++], tab);
	}
	else
	{
		while (s[i])
			display_wchar(s[i++], tab);
	}
	free(s);
	return (tab);
}
