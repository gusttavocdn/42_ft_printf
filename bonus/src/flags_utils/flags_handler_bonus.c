/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_handler_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:10:06 by gusda-si          #+#    #+#             */
/*   Updated: 2023/08/01 02:11:15 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf_bonus.h"

static int	verify_what_flags_i_have(t_flags *flags, const char *str);
static void	verify_width(t_flags *flags, const char *str);
static void	verify_precision(t_flags *flags, const char *str);

int	handle_flags(const char *str, va_list args, int *walked_bytes)
{
	t_flags	flags;
	int		bytes_printed;

	bytes_printed = 0;
	flags = (t_flags){.has_hash = my_false, .has_minus = my_false,
		.has_plus = my_false, .has_space = my_false, .has_zero = my_false,
		.width = -1, .precision = -1, .specifier = 0};
	*walked_bytes += verify_what_flags_i_have(&flags, str);
	bytes_printed += apply_flags(&flags, args);
	return (bytes_printed);
}

static int	verify_what_flags_i_have(t_flags *flags, const char *str)
{
	int	walked_bytes_for_flags;

	walked_bytes_for_flags = 0;
	while (!is_specifier(str[walked_bytes_for_flags])
		&& str[walked_bytes_for_flags] != '\0')
	{
		if (str[walked_bytes_for_flags] == '#')
			flags->has_hash = my_true;
		else if (str[walked_bytes_for_flags] == '0'
			&& !ft_isdigit(str[walked_bytes_for_flags - 1]))
			flags->has_zero = my_true;
		else if (str[walked_bytes_for_flags] == '+')
			flags->has_plus = my_true;
		else if (str[walked_bytes_for_flags] == ' ')
			flags->has_space = my_true;
		else if (str[walked_bytes_for_flags] == '-')
			flags->has_minus = my_true;
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
	while (*str != '\0' && !is_specifier((*str)))
	{
		if (*str != '0' && ft_isdigit(*str) && *(str - 1) != '.')
		{
			flags->width = ft_atoi(str);
			return ;
		}
		str++;
	}
}
