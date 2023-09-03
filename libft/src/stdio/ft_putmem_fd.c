/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmem_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:58:07 by gusda-si          #+#    #+#             */
/*   Updated: 2023/09/02 22:00:17 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

ssize_t	ft_putmem_fd(unsigned long number, int fd)
{
	char	*hex;
	ssize_t	bytes_written;

	hex = ft_itoa_base(number, HEX_LOWER);
	if (!hex)
		return (ft_putstr_fd(NULL, fd));
	bytes_written = ft_putstr_fd("0x", fd);
	bytes_written += ft_putstr_fd(hex, fd);
	free(hex);
	return (bytes_written);
}
