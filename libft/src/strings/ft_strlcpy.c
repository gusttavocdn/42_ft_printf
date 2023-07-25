/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 23:47:40 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/18 08:08:48 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	str_len;

	str_len = ft_strlen(src);
	if ((size <= 0) | !dst)
		return (str_len);
	while (*src != '\0' && size-- > 1)
		*dst++ = *src++;
	*dst = '\0';
	return (str_len);
}
