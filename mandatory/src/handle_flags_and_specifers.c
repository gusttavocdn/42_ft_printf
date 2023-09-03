/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags_and_specifers.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 23:04:17 by gusda-si          #+#    #+#             */
/*   Updated: 2023/09/03 13:15:47 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	verify_what_flags_i_have(t_flags *flags, const char *str);
static void	verify_precision(t_flags *flags, const char *str);
static void	verify_width(t_flags *flags, const char *str);

int	handle_flags_and_specifiers(t_fmt_buffer *buffer, const char *str,
		va_list args)
{
	t_flags	flags;
	int		flags_len;

	flags = (t_flags){.has_hash = false, .has_zero = false, .has_space = false,
		.has_plus = false, .has_minus = false, .specifier = 0, .width = 0,
		.precision = -1};
	flags_len = verify_what_flags_i_have(&flags, str);
	apply_flags_and_specifiers(buffer, &flags, args);
	return (flags_len);
}

static int	verify_what_flags_i_have(t_flags *flags, const char *str)
{
	int	walked_bytes_for_flags;

	walked_bytes_for_flags = 0;
	while (!is_specifier(str[walked_bytes_for_flags])
		&& str[walked_bytes_for_flags] != '\0')
	{
		if (str[walked_bytes_for_flags] == '#')
			flags->has_hash = true;
		else if (str[walked_bytes_for_flags] == '0'
				&& !ft_isdigit(str[walked_bytes_for_flags - 1]))
			flags->has_zero = true;
		else if (str[walked_bytes_for_flags] == '+')
			flags->has_plus = true;
		else if (str[walked_bytes_for_flags] == ' ')
			flags->has_space = true;
		else if (str[walked_bytes_for_flags] == '-')
			flags->has_minus = true;
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
