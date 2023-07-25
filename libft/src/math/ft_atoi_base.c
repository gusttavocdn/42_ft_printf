/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:13:17 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/18 17:53:48 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

#define DECIMAL_BASE "0123456789"
#define DECIMAL_BASE_LEN 10

static int		find_digit_on_base(char digit, char *base);
static t_bool	there_is_base_errors(char *base);

int	ft_atoi_base(char *str, char *base)
{
	int		number;
	int		signal;
	size_t	base_len;

	number = 0;
	base_len = ft_strlen(base);
	if (base_len <= (size_t)1 || there_is_base_errors(base))
		return (number);
	while (ft_isspace(*str))
		str++;
	signal = 1;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			signal *= -1;
		str++;
	}
	while (find_digit_on_base(*str, base) >= 0)
	{
		number *= base_len;
		number += find_digit_on_base(*str, base);
		str++;
	}
	return (number * signal);
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
			return (true);
		if (base[i] == '+' || base[i] == '-')
			return (true);
		j = i + 1;
		while (j < base_len)
		{
			if (base[j] == base[i])
				return (1);
			j++;
		}
		i++;
	}
	return (false);
}

static int	find_digit_on_base(char digit, char *base)
{
	int	digit_position;
	int	digit_not_found;

	digit_position = 0;
	digit_not_found = -1;
	while (base[digit_position] != '\0')
	{
		if (digit == base[digit_position])
			return (digit_position);
		digit_position++;
	}
	return (digit_not_found);
}
