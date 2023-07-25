/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:36:32 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/17 18:59:48 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static size_t	count_digits(long int n);

char	*ft_itoa(int n)
{
	char		*number;
	size_t		size;
	long int	nb;
	size_t		i;

	nb = n;
	size = count_digits(nb);
	number = (char *)ft_calloc(size + NULL_BYTE, sizeof(char));
	if (!number)
		return (NULL);
	i = size - 1;
	if (nb < 0)
	{
		number[0] = '-';
		nb *= -1;
	}
	if (nb == 0)
		number[0] = '0';
	while (nb > 0)
	{
		number[i--] = (nb % 10) + '0';
		nb /= 10;
	}
	number[size] = '\0';
	return (number);
}

static size_t	count_digits(long int n)
{
	size_t	digits;

	digits = 0;
	if (n <= 0)
		digits++;
	while (n)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}
