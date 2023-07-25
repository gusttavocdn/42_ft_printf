/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 21:40:14 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/18 11:59:22 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

ssize_t	ft_putendl_fd(char *s, int fd)
{
	size_t	str_len;
	ssize_t	bytes_written;

	str_len = ft_strlen(s);
	bytes_written = write(fd, s, str_len);
	bytes_written += write(fd, "\n", 1);
	return (bytes_written);
}
