/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags_and_specifiers.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 12:46:09 by gusda-si          #+#    #+#             */
/*   Updated: 2023/10/01 17:11:27 by gusda-si         ###   ########.fr       */
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
	else if (flags->specifier == p)
		apply_pointer(buffer, flags, args);
	else if (flags->specifier == c)
		apply_char(buffer, flags, args);
	else if (flags->specifier == u)
		apply_unsigned_int(buffer, flags, args);
	else if (flags->specifier == percent)
		apply_percent(buffer, flags);
}

void	apply_percent(t_fmt_buffer *buffer, t_flags *flags)
{
	buffer->data[buffer->index++] = percent;
	if (flags->has_minus)
		minus(buffer, flags, 1);
}

void	apply_unsigned_int(t_fmt_buffer *buffer, t_flags *flags, va_list args)
{
	char	*unsigned_str;
	int		number;
	int		len;

	number = va_arg(args, unsigned int);
	unsigned_str = ft_itoa(number);
	len = ft_strlen(unsigned_str);
	if (flags->has_plus && number >= 0)
		plus(buffer);
	width(buffer, flags->precision - len, '0');
	if (flags->has_space && number >= 0)
		space(buffer, flags);
	if (flags->has_zero && !flags->has_minus) // "-" overrides "0"
		zero(buffer, flags, ft_strlen(unsigned_str));
	buffer->index += ft_strlen(unsigned_str);
	ft_strlcat(buffer->data, unsigned_str, BUFFER_SIZE);
	if (flags->has_minus)
		minus(buffer, flags, ft_strlen(unsigned_str));
	width(buffer, flags->width - flags->precision - 1, ' ');
	free(unsigned_str);
}

void	apply_char(t_fmt_buffer *buffer, t_flags *flags, va_list args)
{
	char	c;

	c = va_arg(args, int);
	buffer->data[buffer->index] = c;
	buffer->index++;
	if (flags->has_minus)
		minus(buffer, flags, 1);
}

void	apply_pointer(t_fmt_buffer *buffer, t_flags *flags, va_list args)
{
	char	*pointer_str;
	size_t	pointer;

	pointer = va_arg(args, size_t);
	pointer_str = ft_itoa_base_u(pointer, HEX_LOWER);
	buffer->data[buffer->index++] = '0';
	buffer->data[buffer->index++] = 'x';
	buffer->index += ft_strlen(pointer_str);
	ft_strlcat(buffer->data, pointer_str, BUFFER_SIZE);
	if (flags->has_minus)
		minus(buffer, flags, ft_strlen(pointer_str));
	free(pointer_str);
}

void	apply_string(t_fmt_buffer *buffer, t_flags *flags, va_list args)
{
	char	*string;
	int		len;

	string = va_arg(args, char *);
	if (!string)
		string = "(null)";
	len = ft_strlen(string);
	if (len <= 0)
		return;
	buffer->index += len;
	if (flags->precision != -1 && flags->precision < len)
		buffer->index += flags->precision;

	ft_strncat(buffer->data, string, (flags->precision));
	if (flags->has_minus)
		minus_string(buffer, flags);
}

void	apply_int(t_fmt_buffer *buffer, t_flags *flags, va_list args)
{
	char	*int_str;
	int		number;
	int		len;

	number = va_arg(args, int);
	int_str = ft_itoa(number);
	len = ft_strlen(int_str);
	if (flags->has_plus && number >= 0)
		plus(buffer);
	width(buffer, flags->precision - len, '0');
	if (flags->has_space && number >= 0)
		space(buffer, flags);
	if (flags->has_zero && !flags->has_minus) // "-" overrides "0"
		zero(buffer, flags, ft_strlen(int_str));
	buffer->index += ft_strlen(int_str);
	ft_strlcat(buffer->data, int_str, BUFFER_SIZE);
	if (flags->has_minus)
		minus(buffer, flags, ft_strlen(int_str));
	width(buffer, flags->width - flags->precision - 1, ' ');
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
