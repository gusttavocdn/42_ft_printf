/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags_and_specifier.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 09:43:17 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/29 23:02:17 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

static int	apply_hash_flag(t_flags *flags);
static int	apply_precision(t_flags *flags, char *number);

int	apply_prefix(t_flags *flags, char *number)
{
	int	bytes;

	(void)number;
	bytes = 0;
	if (flags->has_hash && (flags->specifier == 'X' || flags->specifier == 'x'))
		bytes += apply_hash_flag(flags);
	if (flags->has_plus && number[0] != '-')
		bytes += ft_putchar_fd('+', STDOUT_FILENO);
	if (flags->precision > 0)
		bytes += apply_precision(flags, number);
	if (flags->has_zero)
		bytes += apply_width(flags, number, '0');
	if (flags->has_space && number[0] != '-')
		bytes += ft_putchar_fd(' ', STDOUT_FILENO);
	return (bytes);
}

int	apply_width(t_flags *flags, char *number, char padding_char)
{
	int	bytes;
	int	counter;
	int	padding_len;
	int	is_negative;
	int	has_plus;

	bytes = 0;
	counter = 0;
	is_negative = (number[0] == '-');
	has_plus = flags->has_plus;
	padding_len = flags->width - flags->precision - is_negative - has_plus;
	if (flags->precision < 0)
		padding_len = flags->width - (int)ft_strlen(number);
	if (flags->precision < 0 && !ft_strlen(number) && flags->specifier != s)
		padding_len--;
	while (counter < padding_len)
	{
		ft_putchar_fd(padding_char, STDOUT_FILENO);
		counter++;
		bytes++;
	}
	return (bytes);
}

static int	apply_hash_flag(t_flags *flags)
{
	if (flags->specifier == x)
		return ((int)(ft_putstr_fd("0x", STDOUT_FILENO)));
	else
		return ((int)(ft_putstr_fd("0X", STDOUT_FILENO)));
}

static int	apply_precision(t_flags *flags, char *number)
{
	int	bytes;
	int	counter;
	int	is_negative;

	bytes = 0;
	counter = 0;
	is_negative = (number[0] == '-');
	while (counter < (flags->precision - ((int)ft_strlen(number)
				- is_negative)))
	{
		ft_putchar_fd('0', STDOUT_FILENO);
		counter++;
		bytes++;
	}
	return (bytes);
}
