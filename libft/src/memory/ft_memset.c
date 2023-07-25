/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 22:59:27 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/18 11:32:35 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

// NOTES
/*
It is important to cast the void pointer on this function to an unsigned char
this is a way to ensure that we are handling byte to byte
of the memory area pointer by *s

This functions is able to handle memory pointer to several data types.
It kind of data has a specic default byte size to store info.
Example	INT = 4 bytes.
*/

void	*ft_memset(void *s, int c, size_t n)
{
	t_byte_u	*memory_addr;

	memory_addr = (t_byte_u *)s;
	while (n--)
		*memory_addr++ = (t_byte_u)c;
	return (s);
}
