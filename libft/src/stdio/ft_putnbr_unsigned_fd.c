/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 02:38:49 by gusda-si          #+#    #+#             */
/*   Updated: 2023/09/02 22:43:53 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

ssize_t	ft_putnbr_unsigned_fd(unsigned int n, int fd)
{
	char	*number;
	ssize_t	bytes_written;

	number = ft_itoa_base_u(n, DECIMAL);
	if (!number)
		return (ft_putstr_fd(NULL, fd));
	bytes_written = ft_putstr_fd(number, fd);
	free(number);
	return (bytes_written);
}
