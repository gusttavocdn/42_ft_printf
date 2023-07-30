/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:10:06 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/29 21:32:53 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	verify_what_flags_i_have(t_flags *flags, const char *str);
static void	verify_width(t_flags *flags, const char *str);
static void	verify_precision(t_flags *flags, const char *str);
static int	apply_flags(const char *str, t_flags *flags, va_list args);

int	handle_with_flags(const char *str, va_list args, int *walked_bytes,
		int bytes_printed_so_far)
{
	t_flags	flags;
	int		bytes_printed;

	(void)bytes_printed_so_far;
	bytes_printed = 0;
	init_flags(&flags);
	*walked_bytes += verify_what_flags_i_have(&flags, str);
	bytes_printed += apply_flags(str, &flags, args);
	return (bytes_printed);
}

static int	verify_what_flags_i_have(t_flags *flags, const char *str)
{
	int	walked_bytes_for_flags;

	walked_bytes_for_flags = 0;
	while (!it_is_a_specifier(str[walked_bytes_for_flags])
		&& str[walked_bytes_for_flags] != '\0')
	{
		if (str[walked_bytes_for_flags] == '#')
			flags->has_hash = my_true;
		else if (str[walked_bytes_for_flags] == '0'
			&& !ft_isdigit(str[walked_bytes_for_flags - 1]))
			flags->has_zero = my_true;
		else if (str[walked_bytes_for_flags] == '+')
			flags->has_plus = my_true;
		walked_bytes_for_flags++;
	}
	verify_width(flags, str);
	verify_precision(flags, str);
	flags->specifier = (t_specifiers)str[walked_bytes_for_flags];
	return (walked_bytes_for_flags + 1);
}

static void	verify_precision(t_flags *flags, const char *str)
{
	char	*precision;

	precision = ft_strchr(str, '.');
	if (precision)
		flags->precision = ft_atoi(precision + 1);
	else
		flags->precision = -1;
}

static void	verify_width(t_flags *flags, const char *str)
{
	while (*str != '\0' && !it_is_a_specifier((*str)))
	{
		if (*str != '0' && ft_isdigit(*str) && *(str - 1) != '.')
		{
			flags->width = ft_atoi(str);
			return ;
		}
		str++;
	}
}

static int	apply_flags(const char *str, t_flags *flags, va_list args)
{
	int		bytes;
	char	*argument;
	size_t	argument_ptr;

	(void)str;
	bytes = 0;
	argument_ptr = 0;
	argument = get_argument(flags->specifier, args);
	if (*argument == '0')
	{
		free(argument);
		return ((int)ft_putchar_fd('0', STDOUT_FILENO));
	}
	if (!flags->has_zero)
		bytes += apply_width(flags, argument, ' ');
	if (argument[argument_ptr] == '-' && flags->specifier != s)
	{
		bytes += (int)ft_putchar_fd('-', STDOUT_FILENO);
		argument_ptr++;
	}
	bytes += apply_prefix(flags, argument);
	bytes += (int)ft_putstr_fd(&argument[argument_ptr], STDOUT_FILENO);
	free(argument);
	return (bytes);
}