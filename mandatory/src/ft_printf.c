/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:10:29 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/29 21:33:45 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	print_format(const char *str, va_list args);
static int	handle_flags_and_specifiers(const char *str, va_list args,
				int *bytes);

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		bytes_printed;

	va_start(args, str);
	bytes_printed = print_format(str, args);
	va_end(args);
	return (bytes_printed);
}

static int	print_format(const char *str, va_list args)
{
	int	bytes_printed;

	bytes_printed = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			str += handle_flags_and_specifiers(str, args, &bytes_printed);
		}
		else
			bytes_printed += (int)ft_putchar_fd(*str++, STDOUT_FILENO);
	}
	return (bytes_printed);
}

// TODO: Implement function to handle flags
static int	handle_flags_and_specifiers(const char *str, va_list args,
		int *bytes)
{
	int	walked_bytes;

	walked_bytes = 0;
	if (it_is_a_specifier(str[0]))
	{
		*bytes += handle_with_just_specifier(str[0], args);
		walked_bytes = 1;
	}
	else if (it_is_a_flag(str[0]) || ft_atoi(str) > 0)
		*bytes += handle_with_flags(&str[walked_bytes], args, &walked_bytes);
	return (walked_bytes);
}
