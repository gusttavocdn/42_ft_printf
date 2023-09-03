/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 21:38:48 by gusda-si          #+#    #+#             */
/*   Updated: 2023/09/02 22:58:08 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

ssize_t	ft_putstr_fd(char *s, int fd)
{
	size_t	str_len;

	if (!s)
		return (write(fd, "(null)", 6));
	str_len = ft_strlen(s);
	return (write(fd, s, str_len));
}
