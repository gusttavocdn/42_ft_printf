/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 01:33:10 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/17 19:14:44 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*s;

	s = (unsigned char *)str;
	while (n--)
	{
		if (*s == (unsigned char)c)
			return ((void *)s);
		s++;
	}
	return (NULL);
}
