/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/* hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023-10-01 22:23:46 by gusda-si          #+#    #+#             */
/*   Updated: 2023-10-01 22:23:46 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	fmt_hex(t_fmt_buffer *buffer, t_flags *flags, va_list args)
{
	char			*hex_str;
	unsigned int	number;

	number = va_arg(args, size_t);
	if (flags->specifier == x)
		hex_str = ft_itoa_base_u(number, HEX_LOWER);
	else
		hex_str = ft_itoa_base_u(number, HEX_UPPER);
	if (flags->has_hash)
		hash(buffer, flags);
	buffer->size += (int)ft_strlen(hex_str);
	ft_strlcat(buffer->data, hex_str, BUFFER_SIZE);
	if (flags->has_minus)
		minus(buffer, flags, (int)ft_strlen(hex_str));
	free(hex_str);
}
