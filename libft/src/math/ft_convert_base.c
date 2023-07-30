/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:39:39 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/19 12:12:06 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static t_bool	there_is_base_errors(char *base);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nbr_in_decimal;
	char	*converted_number;

	if (there_is_base_errors(base_from) || there_is_base_errors(base_to))
		return (NULL);
	nbr_in_decimal = ft_atoi_base(nbr, base_from);
	converted_number = ft_itoa_base(nbr_in_decimal, base_to);
	return (converted_number);
}

static t_bool	there_is_base_errors(char *base)
{
	int	i;
	int	j;
	int	base_len;

	i = 0;
	base_len = ft_strlen(base);
	while (i < base_len)
	{
		if (ft_isspace(base[i]))
			return (my_true);
		if (base[i] == '+' || base[i] == '-')
			return (my_true);
		j = i + 1;
		while (j < base_len)
		{
			if (base[j] == base[i])
				return (1);
			j++;
		}
		i++;
	}
	return (my_false);
}
