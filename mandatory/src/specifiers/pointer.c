/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 22:26:01 by gusda-si          #+#    #+#             */
/*   Updated: 2023/10/02 00:05:32 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	calc_width_len(int buffer_size, t_flags *flags);

void	fmt_pointer(t_fmt_buffer *buffer, t_flags *flags, va_list args)
{
	char	*pointer_str;
	size_t	pointer;
	int		pointer_len;

	pointer = va_arg(args, size_t);
	if (!pointer)
	{
		if (!flags->has_minus)
			width(buffer, calc_width_len(5, flags), ' ');
		buffer->size += 5;
		ft_strlcat(buffer->data, "(nil)", BUFFER_SIZE);
		return ;
	}
	pointer_str = ft_itoa_base_ul(pointer, HEX_LOWER);
	pointer_len = (int)ft_strlen(pointer_str);
	if (!flags->has_minus)
		width(buffer, calc_width_len(pointer_len + 2, flags), ' ');
	buffer->data[buffer->size++] = '0';
	buffer->data[buffer->size++] = 'x';
	buffer->size += pointer_len;
	ft_strlcat(buffer->data, pointer_str, BUFFER_SIZE);
	if (flags->has_minus)
		minus(buffer, flags, pointer_len + 2);
	free(pointer_str);
}

static int	calc_width_len(int str_size, t_flags *flags)
{
	if (flags->width > 0 && flags->width > str_size)
	{
		if (str_size > flags->width)
			return (str_size);
		return (flags->width - str_size);
	}
	return (0);
}
