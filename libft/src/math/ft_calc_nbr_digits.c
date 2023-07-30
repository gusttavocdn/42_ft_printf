/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_nbr_digits.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:35:39 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/30 17:59:19 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_calc_nbr_digits(long int number, int base_len)
{
	int	digits;

	digits = 1;
	if (number < 0)
		digits++;
	number /= base_len;
	while (number)
	{
		digits++;
		number /= base_len;
	}
	return (digits);
}
