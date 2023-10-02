/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:10:29 by gusda-si          #+#    #+#             */
/*   Updated: 2023/10/01 23:13:29 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	print_format(const char *str, va_list args);
static int	print_buffer(t_fmt_buffer *buffer);

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		bytes_printed;

	va_start(args, str);
	bytes_printed = print_format(str, args);
	va_end(args);
	return (bytes_printed);
}

static int	print_format(const char *str, va_list args)
{
	t_fmt_buffer	buffer;
	int				bytes_printed;

	buffer.data = ft_calloc(BUFFER_SIZE + NULL_BYTE, sizeof(char));
	buffer.size = 0;
	bytes_printed = 0;
	while (*str != '\0')
	{
		if (*str == percent)
		{
			str++;
			str += handle_flags_and_specifiers(&buffer, str, args);
		}
		else
			buffer.data[buffer.size++] = *str++;
		if (*str == '\n' || buffer.size == BUFFER_SIZE)
		{
			buffer.data[buffer.size++] = *str++;
			bytes_printed += print_buffer(&buffer);
		}
	}
	bytes_printed += print_buffer(&buffer);
	free(buffer.data);
	return (bytes_printed);
}

static int	print_buffer(t_fmt_buffer *buffer)
{
	int	bytes_printed;

	bytes_printed = 0;
	bytes_printed = (int)ft_putstr_fd(&buffer->data[bytes_printed],
			STDOUT_FILENO);
	while (buffer->data[bytes_printed] == '\0' && buffer->data[bytes_printed
			+ 1])
	{
		bytes_printed += (int)write(STDOUT_FILENO, "\0", 1);
		bytes_printed += (int)ft_putstr_fd(&buffer->data[bytes_printed],
				STDOUT_FILENO);
	}
	if (buffer->size == (bytes_printed + 1))
		bytes_printed += write(STDOUT_FILENO, "\0", 1);
	ft_bzero(buffer->data, buffer->size);
	buffer->size = 0;
	return (bytes_printed);
}
