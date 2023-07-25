/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 23:47:57 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/18 08:08:42 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	final_len;

	src_len = ft_strlen(src);
	if (!dst || size == 0)
		return (src_len + size);
	dest_len = ft_strlen(dst);
	final_len = dest_len + src_len;
	if (size > dest_len)
	{
		while ((*src != '\0') && (dest_len < size - 1))
			dst[dest_len++] = *src++;
		dst[dest_len] = '\0';
		return (final_len);
	}
	return (src_len + size);
}
