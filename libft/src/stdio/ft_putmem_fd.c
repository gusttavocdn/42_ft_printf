/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/* ft_putmem_fd.c                                         :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023-07-28 14:58:07 by gusda-si          #+#    #+#             */
/*   Updated: 2023-07-28 14:58:07 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

ssize_t	ft_putmem_fd(unsigned long number, int fd)
{
	ssize_t	bytes_written;

	bytes_written = 0;
	if (number >= HEX_SIZE)
		bytes_written += ft_putmem_fd(number / HEX_SIZE, fd);
	bytes_written += ft_putchar_fd(HEX_LOWER[number % HEX_SIZE], fd);
	return (bytes_written);
}
