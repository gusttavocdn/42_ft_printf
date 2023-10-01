/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_ul                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 17:21:42 by gusda-si          #+#    #+#             */
/*   Updated: 2023/10/01 17:22:23 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	ft_calc_nbr_digits_u(size_t number, int base_len);

char	*ft_itoa_base_ul(unsigned long number, char *base)
{
	char	*number_str;
	int		number_len;
	int		base_len;

	base_len = ft_strlen(base);
	number_len = ft_calc_nbr_digits_u(number, base_len);
	number_str = (char *)ft_calloc(number_len + NULL_BYTE, sizeof(char));
	if (!number_str)
		return (NULL);
	if (number == 0)
		number_str[0] = '0';
	while (number != 0)
	{
		number_str[--number_len] = base[number % base_len];
		number /= base_len;
	}
	return (number_str);
}

static int	ft_calc_nbr_digits_u(size_t number, int base_len)
{
	int	digits;

	digits = 1;
	number /= base_len;
	while (number)
	{
		digits++;
		number /= base_len;
	}
	return (digits);
}
