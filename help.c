/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrigett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 18:51:18 by jbrigett          #+#    #+#             */
/*   Updated: 2020/07/16 18:51:20 by jbrigett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 	ft_max(a, b)
{
	return (a > b ? a : b);
}

void			buffer(t_printf *p, void *new, size_t size)
{
	long		new_i;
	int			diff;

	new_i = 0;
	while (PF_BUF_SIZE - p->buffer_index < size)
	{
		diff = PF_BUF_SIZE - p->buffer_index;
		ft_memcpy((char *)(p->buff + p->buffer_index), \
												(char *)(new + new_i), diff);
		size -= diff;
		new_i += diff;
		p->buffer_index += diff;
		p->len += diff;
		if (write(p->fd, p->buff, p->buffer_index) == -1)
			return ;
		p->buffer_index = 0;
	}
	ft_memcpy((char *)(p->buff + p->buffer_index), (char *)(new + new_i), size);
	p->buffer_index += size;
	p->len += size;
}

void			buffered_print(void *void_data, size_t size, t_buffer *buf)
{
	uint32_t	leftover;
	uint8_t		*data;
	int64_t		i;

	data = (uint8_t *) ;
	i = 0;
	while (size > (X64_SIZE - buf->buffer_index))
	{
		leftover = X64_SIZE - buf->buffer_index;
		ft_memcpy(&(buf->buffer[buf->buffer_index]), &(data[i]), leftover);
		size -= leftover;
		i += leftover;
		buf->buffer_index += leftover;
		buf->bytes_written += leftover;
		write(1, buf->buffer, buf->buffer_index);
		buf->buffer_index = 0;
	}
	ft_memcpy(&(buf->buffer[buf->buffer_index]), &(data[i]), size);
	buf->buffer_index += size;
	buf->bytes_written += size;
}

void	display_gap(t_tab *tab, char c, int len, int update_len)
{
	char	*str;

	if (len > 0)
	{
		if (update_len)
			tab->len += len;
		if (!(str = ft_strnew(len)))
			exit(-1);
		ft_memset(str, c, len);
		write(1, str, len);
		free(str);
	}
}

static void	init_buffer(t_buffer *buffer)
{
	int32_t	i;

	i = 64;
	buffer->buffer_index = 0;
	while (i-- >= 0)
		buffer->buffer[i] = 0;
	buffer->bytes_written = 0;
	buffer->undefined_behaviour = 0;
}

static void	init_format(t_format *format)
{
	format->fl = 0;
	format->width = 0;
	format->prec = 1;
	format->to_print = 0;
	format->spec = '\0';
	format->base = 0;
	format->fd = 1;
}

int8_t	ft_isupper(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

void	padding(char *c, int32_t padding, t_buffer *buffer)
{
	while (padding-- > 0)
		buffered_print(c, 1, buffer);
}

size_t	length_base(uintmax_t n, int8_t base)
{
	size_t	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n > 0)
	{
		n /= base;
		len++;
	}
	return (len);
}
