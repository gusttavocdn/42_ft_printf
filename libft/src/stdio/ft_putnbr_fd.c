/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 21:42:49 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/18 17:11:05 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

ssize_t	ft_putnbr_fd(long int n, int fd)
{
	t_byte_u	base_len;
	ssize_t		bytes_written;

	bytes_written = 0;
	base_len = 10;
	if (n < 0)
	{
		bytes_written += ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n >= base_len)
		bytes_written += ft_putnbr_fd(n / 10, fd);
	bytes_written += ft_putchar_fd((n % 10) + '0', fd);
	return (bytes_written);
}
