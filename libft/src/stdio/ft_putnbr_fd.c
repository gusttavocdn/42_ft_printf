/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 21:42:49 by gusda-si          #+#    #+#             */
/*   Updated: 2023/09/02 22:00:19 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

ssize_t	ft_putnbr_fd(long int n, int fd)
{
	char *number;
	ssize_t bytes_written;

	number = ft_itoa(n);
	if (!number)
		return ft_putstr_fd(NULL, fd);
	bytes_written = ft_putstr_fd(number, fd);
	free(number);
	return (bytes_written);
}
