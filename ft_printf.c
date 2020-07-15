# include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	va_list		ap;
	char		*str;
	t_buffer	buf;

	str = (char *)format;
	init_buffer(&buf);
	va_start(ap,format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			++format;
			format = parser(format, &ap, &buf);
		}
		else
			PRINT(str++, 1, &buf);
	}
	write(1, buf.buffer, buf.buffer_index);
	va_end(ap);
	return (buf.bytes_written);
}