/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:10:29 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/26 14:41:07 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		print_format(const char *str, va_list args);
static int		handle_flag_specifier(const char *str, va_list args,
					int *bytes);
// static t_bool	it_is_a_flag(char flag);
static t_bool	is_is_a_specifier(char flag);

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
			str += handle_flag_specifier(++str, args, &bytes_printed);
		else
		{
			bytes_printed += ft_putchar_fd(*str, STDOUT_FILENO);
			str++;
		}
	}
	return (bytes_printed);
}

// TODO: Implement function to handle flags
static int	handle_flag_specifier(const char *str, va_list args, int *bytes)
{
	if (is_is_a_specifier(str[0]))
	{
		*bytes += handle_specifier(str[0], str, args);
		return (1);
	}
	// if (it_is_a_flag(str[0]))
	// 	return (handle_flag(str[0], str, args));
	return (1);
}

// static t_bool	it_is_a_flag(char flag)
// {
// 	size_t	counter;

// 	counter = 0;
// 	while (FLAGS[counter] != '\0')
// 	{
// 		if (FLAGS[counter] == flag)
// 			return (TRUE);
// 		counter++;
// 	}
// 	return (FALSE);
// }

static t_bool	is_is_a_specifier(char flag)
{
	size_t	counter;

	counter = 0;
	while (CONVERSIONS[counter] != '\0')
	{
		if (CONVERSIONS[counter] == flag)
			return (TRUE);
		counter++;
	}
	return (FALSE);
}
