/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 02:14:18 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/19 12:12:15 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_atoi(const char *str)
{
	int	number;
	int	signal;

	while (ft_isspace(*str))
		str++;
	signal = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			signal *= -1;
		str++;
	}
	number = 0;
	while ((*str >= '0' && *str <= '9') && (*str != '\0'))
	{
		number *= 10;
		number += *str - '0';
		str++;
	}
	return (number * signal);
}
