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

int	apply_precision(t_flags *flags, char *number)
{
	int	bytes;
	int	counter;
	int	is_negative;

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
