/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 01:02:35 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/18 11:32:33 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

// NOTES
/* This functions works pretty similar to ft_memcpy.
 * The main difference is that it can handle overlapping memory.
 * This can happen if in some case we try to copy data that
 * are very near to each other. Like manipulation to index of the same array.
*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	t_byte_u		*dest_ptr;
	const t_byte_u	*src_ptr;

	if (!dest && !src)
		return (NULL);
	src_ptr = src;
	dest_ptr = dest;
	if (dest_ptr < src_ptr)
	{
		while (n--)
			*dest_ptr++ = *src_ptr++;
		return (dest);
	}
	while (n--)
		*(dest_ptr + n) = *(src_ptr + n);
	return (dest);
}
