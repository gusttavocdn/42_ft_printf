/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:54:35 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/31 16:43:32 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf_bonus.h"

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
