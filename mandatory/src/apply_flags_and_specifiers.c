/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags_and_specifiers.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 12:46:09 by gusda-si          #+#    #+#             */
/*   Updated: 2023/09/03 13:51:27 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	apply_flags_and_specifiers(t_fmt_buffer *buffer,
								t_flags *flags,
								va_list args)
{
	if (flags->specifier == x || flags->specifier == X)
		apply_hex(buffer, flags, args);
	if (flags->specifier == o)
		apply_octal(buffer, flags, args);
}

void apply_octal(t_fmt_buffer *buffer, t_flags *flags, va_list args)
{
	char			*octal_str;
	unsigned int	number;

	number = va_arg(args, size_t);
	octal_str = ft_itoa_base_u(number, OCTAL);
	if (flags->has_hash)
		hash(buffer, flags, args);
	buffer->index += ft_strlen(octal_str);
	ft_strlcat(buffer->data, octal_str, BUFFER_SIZE);
	free(octal_str);
}

void	apply_hex(t_fmt_buffer *buffer, t_flags *flags, va_list args)
{
	char			*hex_str;
	unsigned int	number;

	number = va_arg(args, size_t);
	if (flags->specifier == x)
		hex_str = ft_itoa_base_u(number, HEX_LOWER);
	else
		hex_str = ft_itoa_base_u(number, HEX_UPPER);
	if (flags->has_hash)
		hash(buffer, flags, args);
	buffer->index += ft_strlen(hex_str);
	ft_strlcat(buffer->data, hex_str, BUFFER_SIZE);
	free(hex_str);
}
