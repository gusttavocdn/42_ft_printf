/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:51:04 by gusda-si          #+#    #+#             */
/*   Updated: 2023/08/01 13:04:46 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	handle_p_specifier(va_list args);

int	handle_just_specifier(char specifier, va_list args)
{
	if (specifier == 'c')
		return ((int)ft_putchar_fd(va_arg(args, int), STDOUT_FILENO));
	if (specifier == 's')
		return ((int)ft_putstr_fd(va_arg(args, char *), STDOUT_FILENO));
	if (specifier == 'd' || specifier == 'i')
		return ((int)ft_putnbr_fd(va_arg(args, int), STDOUT_FILENO));
	if (specifier == 'x')
		return ((int)ft_putnbr_base(va_arg(args, unsigned int), HEX_LOWER,
				STDOUT_FILENO));
	if (specifier == 'X')
		return ((int)ft_putnbr_base(va_arg(args, unsigned int), HEX_UPPER,
				STDOUT_FILENO));
	if (specifier == '%')
		return ((int)ft_putchar_fd('%', STDOUT_FILENO));
	if (specifier == 'u')
		return ((int)ft_putnbr_unsigned_fd(va_arg(args, unsigned int),
				STDOUT_FILENO));
	if (specifier == 'p')
		return (handle_p_specifier(args));
	return (1);
}

static int	handle_p_specifier(va_list args)
{
	int				bytes_printed;
	size_t	pointer;

	pointer = va_arg(args, size_t);
	if (!pointer)
		return ((int)ft_putstr_fd("(nil)", STDOUT_FILENO));
	bytes_printed = 0;
	bytes_printed += (int)ft_putstr_fd("0x", STDOUT_FILENO);
	bytes_printed += (int)ft_putmem_fd(pointer, STDOUT_FILENO);
	return (bytes_printed);
}
