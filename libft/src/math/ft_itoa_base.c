/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:30:20 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/29 21:44:54 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_itoa_base(long int number, char *base)
{
	char		*number_str;
	int			number_len;
	int			base_len;
	long int	nbr;

	nbr = number;
	base_len = ft_strlen(base);
	number_len = ft_calc_nbr_digits(number, base_len);
	number_str = (char *)malloc(number_len + sizeof(char));
	if (!number_str)
		return (NULL);
	if (nbr == 0)
		number_str[0] = '0';
	number_str[number_len] = '\0';
	if (nbr < 0)
	{
		number_str[0] = '-';
		nbr *= -1;
	}
	while (nbr != 0)
	{
		number_str[--number_len] = base[nbr % base_len];
		nbr /= base_len;
	}
	return (number_str);
}
