/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 06:30:04 by gusda-si          #+#    #+#             */
/*   Updated: 2023/09/02 22:00:19 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	there_is_base_errors(char *base);

ssize_t	ft_putnbr_base(long int nbr, char *base, int fd)
{
	int		base_len;
	char	*number;
	ssize_t	bytes_written;

	base_len = ft_strlen(base);
	if (base_len <= 1 || there_is_base_errors(base))
		return (0);
	number = ft_itoa_base(nbr, base);
	if (!number)
		return (ft_putstr_fd(NULL, fd));
	bytes_written = ft_putstr_fd(number, fd);
	free(number);
	return (bytes_written);
}

static int	there_is_base_errors(char *base)
{
	int	i;
	int	j;
	int	base_len;

	i = 0;
	base_len = ft_strlen(base);
	while (i < base_len)
	{
		if (base[i] == '\t' || base[i] == '\n' || base[i] == '\v'
			|| base[i] == '\f' || base[i] == '\r' || base[i] == ' ')
			return (1);
		if (base[i] == '+' || base[i] == '-')
			return (1);
		j = i + 1;
		while (j < base_len)
		{
			if (base[j] == base[i])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
