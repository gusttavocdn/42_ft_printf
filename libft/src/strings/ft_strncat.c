/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 12:56:16 by gusda-si          #+#    #+#             */
/*   Updated: 2023/10/01 13:00:22 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int	dest_len;
	int	src_len;

	dest_len = ft_strlen(dest);
	src_len = 0;
	while (src[src_len] != '\0' && nb-- > 0)
		dest[dest_len++] = src[src_len++];
	dest[dest_len] = '\0';
	return (dest);
}
