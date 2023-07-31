/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:12:57 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/31 16:43:38 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf_bonus.h"

static int	apply_prefix(t_flags *flags, char *number);
static int	apply_posfix(t_flags *flags, char *number);

int	apply_flags(t_flags *flags, va_list args)
{
	int		bytes;
	char	*argument;
	size_t	argument_ptr;

	bytes = 0;
	argument_ptr = 0;
	argument = convert_specifier_to_str(flags->specifier, args);
	if (*argument == '0' && *(argument + 1) == '\0' && flags->specifier == s)
		bytes += ((int)ft_putchar_fd('0', STDOUT_FILENO));
	else if (*argument == '\0' && flags->specifier == c)
		bytes += ((int)ft_putchar_fd('\0', STDOUT_FILENO));
	else
	{
		if (!flags->has_zero && !flags->has_minus && flags->width > 0)
			bytes += apply_width(flags, argument, ' ');
		if (argument[argument_ptr] == '-' && flags->specifier != s)
		{
			bytes += (int)ft_putchar_fd('-', STDOUT_FILENO);
			argument_ptr++;
		}
		bytes += apply_prefix(flags, argument);
		bytes += (int)ft_putstr_fd(&argument[argument_ptr], STDOUT_FILENO);
	}
	bytes += apply_posfix(flags, argument);
	free(argument);
	return (bytes);
}

static int	apply_prefix(t_flags *flags, char *number)
{
	int	bytes;

	bytes = 0;
	if (flags->has_hash && (flags->specifier == 'X' || flags->specifier == 'x'))
		bytes += apply_hash(flags);
	if (flags->has_plus && number[0] != '-')
		bytes += apply_plus(flags);
	if (flags->precision > 0 && flags->specifier != s)
		bytes += apply_precision(flags, number);
	if (flags->has_zero)
		bytes += apply_width(flags, number, '0');
	if (flags->has_space && number[0] != '-')
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
