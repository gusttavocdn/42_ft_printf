/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 00:22:37 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/18 08:09:54 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*s;
	size_t	str_len;

	str_len = ft_strlen(str);
	s = (char *)str + str_len;
	while (str_len--)
	{
		if (*s == (unsigned char)c)
			return (s);
		s--;
	}
	if (*s == (unsigned char)c)
		return (s);
	return (NULL);
}
