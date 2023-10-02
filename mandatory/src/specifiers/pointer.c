/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 22:26:01 by gusda-si          #+#    #+#             */
/*   Updated: 2023/10/01 22:26:06 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	fmt_pointer(t_fmt_buffer *buffer, t_flags *flags, va_list args)
{
	char	*pointer_str;
	size_t	pointer;

	pointer = va_arg(args, size_t);
	if (!pointer)
	{
		buffer->index += 5;
		ft_strlcat(buffer->data, "(nil)", BUFFER_SIZE);
		return ;
	}
	pointer_str = ft_itoa_base_ul(pointer, HEX_LOWER);
	buffer->data[buffer->index++] = '0';
	buffer->data[buffer->index++] = 'x';
	buffer->index += (int)ft_strlen(pointer_str);
	ft_strlcat(buffer->data, pointer_str, BUFFER_SIZE);
	if (flags->has_minus)
		minus(buffer, flags, ft_strlen(pointer_str));
	free(pointer_str);
}
