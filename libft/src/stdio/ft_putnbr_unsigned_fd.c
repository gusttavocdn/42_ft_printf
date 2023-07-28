/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 02:38:49 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/27 03:06:02 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

ssize_t	ft_putnbr_unsigned_fd(unsigned int n, int fd)
{
	t_byte_u	base_len;
	ssize_t		bytes_written;

	bytes_written = 0;
	base_len = 10;
	if (n >= base_len)
		bytes_written += ft_putnbr_unsigned_fd(n / base_len, fd);
	bytes_written += ft_putchar_fd((n % 10) + '0', fd);
	return (bytes_written);
}
