/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_specifiers.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 12:46:09 by gusda-si          #+#    #+#             */
/*   Updated: 2023/10/01 22:26:24 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	fmt_specifiers(t_fmt_buffer *buffer,
					t_flags *flags,
					va_list args)
{
	if (flags->specifier == x || flags->specifier == X)
		fmt_hex(buffer, flags, args);
	else if (flags->specifier == o)
		fmt_octal(buffer, flags, args);
	else if (flags->specifier == d || flags->specifier == i)
		fmt_int(buffer, flags, args);
	else if (flags->specifier == s)
		fmt_str(buffer, flags, args);
	else if (flags->specifier == p)
		fmt_pointer(buffer, flags, args);
	else if (flags->specifier == c)
		fmt_char(buffer, flags, args);
	else if (flags->specifier == u)
		fmt_unsigned_int(buffer, flags, args);
	else if (flags->specifier == percent)
		fmt_percent(buffer, flags);
}

void	fmt_percent(t_fmt_buffer *buffer, t_flags *flags)
{
	buffer->data[buffer->index++] = percent;
	if (flags->has_minus)
		minus(buffer, flags, 1);
}
