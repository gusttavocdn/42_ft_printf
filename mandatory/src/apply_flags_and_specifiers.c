/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags_and_specifiers.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 12:46:09 by gusda-si          #+#    #+#             */
/*   Updated: 2023/09/30 01:28:14 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	apply_flags_and_specifiers(t_fmt_buffer *buffer,
								t_flags *flags,
								va_list args)
{
	if (flags->specifier == x || flags->specifier == X)
		apply_hex(buffer, flags, args);
	else if (flags->specifier == o)
		apply_octal(buffer, flags, args);
	else if (flags->specifier == d || flags->specifier == i)
		apply_int(buffer, flags, args);
	else if (flags->specifier == s)
		apply_string(buffer, flags, args);
}

void apply_string(t_fmt_buffer *buffer, t_flags *flags, va_list args)
{
	char	*string;
	int		len;

	string = va_arg(args, char *);
	len = ft_strlen(string);
	buffer->index += len;
	ft_strlcat(buffer->data, string, BUFFER_SIZE);
	if (flags->has_minus)
		minus(buffer, flags, len);
}

void	apply_int(t_fmt_buffer *buffer, t_flags *flags, va_list args)
{
	char	*int_str;
	int		number;

	number = va_arg(args, int);
	int_str = ft_itoa(number);
	if (flags->has_plus && number >= 0)
		plus(buffer, flags);
	if (flags->has_space && number >= 0)
		space(buffer, flags);
	if (flags->has_zero && !flags->has_minus) // "-" overrides "0"
		zero(buffer, flags, ft_strlen(int_str));
	buffer->index += ft_strlen(int_str);
	ft_strlcat(buffer->data, int_str, BUFFER_SIZE);
	if (flags->has_minus)
		minus(buffer, flags, ft_strlen(int_str));
	free(int_str);
}

void	apply_octal(t_fmt_buffer *buffer, t_flags *flags, va_list args)
{
	char			*octal_str;
	unsigned int	number;

	number = va_arg(args, size_t);
	octal_str = ft_itoa_base_u(number, OCTAL);
	if (flags->has_hash)
		hash(buffer, flags);
	buffer->index += ft_strlen(octal_str);
	ft_strlcat(buffer->data, octal_str, BUFFER_SIZE);
	if (flags->has_minus)
		minus(buffer, flags, ft_strlen(octal_str));
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
		hash(buffer, flags);
	buffer->index += ft_strlen(hex_str);
	ft_strlcat(buffer->data, hex_str, BUFFER_SIZE);
	if (flags->has_minus)
		minus(buffer, flags, ft_strlen(hex_str));
	free(hex_str);
}
