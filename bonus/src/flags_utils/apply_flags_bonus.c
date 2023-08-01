/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:12:57 by gusda-si          #+#    #+#             */
/*   Updated: 2023/08/01 02:11:14 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf_bonus.h"

static int	apply_prefix(t_flags *flags, char *number);
static int	apply_posfix(t_flags *flags, char *number);
static int	handle_edge_cases(t_flags *flags, char *format);
static int	print_minus(t_flags *flags, char *format, int *bytes);

int	apply_flags(t_flags *flags, va_list args)
{
	int		bytes;
	char	*format;
	size_t	format_index;

	bytes = 0;
	format_index = 0;
	format = convert_specifier_to_str(flags->specifier, args);
	if (handle_edge_cases(flags, format))
		bytes++;
	else
	{
		if (!flags->has_zero && !flags->has_minus && flags->width > 0)
			bytes += apply_width(flags, format, ' ');
		format_index += print_minus(flags, format, &bytes);
		bytes += apply_prefix(flags, format);
		if (flags->specifier != s || flags->precision < 0)
			bytes += (int)ft_putstr_fd(&format[format_index], STDOUT_FILENO);
	}
	bytes += apply_posfix(flags, format);
	free(format);
	return (bytes);
}

static int	apply_prefix(t_flags *flags, char *format)
{
	int	bytes;

	bytes = 0;
	if (flags->has_hash && (flags->specifier == 'X' || flags->specifier == 'x'))
		bytes += apply_hash(flags, format);
	if (flags->has_plus && format[0] != '-')
		bytes += apply_plus(flags);
	if (flags->precision > 0)
		bytes += apply_precision(flags, format);
	if (flags->has_zero)
		bytes += apply_width(flags, format, '0');
	if (flags->has_space && format[0] != '-')
		bytes += apply_space(flags);
	return (bytes);
}

static int	apply_posfix(t_flags *flags, char *number)
{
	int	bytes;

	bytes = 0;
	if (flags->has_minus)
		bytes += apply_width(flags, number, ' ');
	return (bytes);
}

static int	handle_edge_cases(t_flags *flags, char *format)
{
	if (*format == '0' && *(format + 1) == '\0' && flags->specifier == s)
		return ((int)ft_putchar_fd('0', STDOUT_FILENO));
	else if (*format == '\0' && flags->specifier == c)
		return ((int)ft_putchar_fd('\0', STDOUT_FILENO));
	return (0);
}

static int	print_minus(t_flags *flags, char *format, int *bytes)
{
	if (format[0] == '-' && flags->specifier != s)
	{
		*bytes += 1;
		return ((int)ft_putchar_fd('-', STDOUT_FILENO));
	}
	return (0);
}
