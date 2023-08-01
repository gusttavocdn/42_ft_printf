/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:59:21 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/31 16:43:34 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf_bonus.h"

static int	apply_precision_for_s_specifier(t_flags *flags, char *format);

int	apply_precision(t_flags *flags, char *number)
{
	int	bytes;
	int	counter;
	int	is_negative;

	if (flags->specifier == s)
		return (apply_precision_for_s_specifier(flags, number));
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

static int	apply_precision_for_s_specifier(t_flags *flags, char *format)
{
	int	bytes;

	bytes = 0;
	while (bytes < flags->precision && format[bytes])
	{
		ft_putchar_fd(format[bytes], STDOUT_FILENO);
		bytes++;
	}
	return (bytes);
}
