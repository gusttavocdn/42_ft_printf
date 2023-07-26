/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_flag_handler.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:51:04 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/26 14:17:38 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// TODO: Handle specifiers p and u
int	handle_specifier(char specifier, const char *str, va_list args)
{
	if (specifier == 'c')
		return (ft_putchar_fd(va_arg(args, int), STDOUT_FILENO));
	if (specifier == 's')
		return (ft_putstr_fd(va_arg(args, char *), STDOUT_FILENO));
	if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr_fd(va_arg(args, int), STDOUT_FILENO));
	if (specifier == 'x')
		return (ft_putnbr_base(va_arg(args, int), HEX_LOWER_BASE,
				STDOUT_FILENO));
	if (specifier == 'X')
		return (ft_putnbr_base(va_arg(args, int), HEX_UPPER_BASE,
				STDOUT_FILENO));
	if (specifier == '%')
		return (ft_putchar_fd('%', STDOUT_FILENO));
	return (1);
}
