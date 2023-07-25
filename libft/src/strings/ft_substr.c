/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 13:13:15 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/25 18:36:53 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	substr_len;
	size_t	source_len;
	char	*substr;

	if (!s)
		return (NULL);
	source_len = ft_strlen(s);
	substr_len = source_len - (size_t)start;
	if (start > source_len || !substr_len)
		return ((char *)ft_calloc(1, sizeof(char)));
	if (substr_len > len)
		substr_len = len;
	if (len > source_len && substr_len > source_len)
		substr_len = source_len;
	substr = (char *)ft_calloc(substr_len + NULL_BYTE, sizeof(char));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, (s + start), substr_len + NULL_BYTE);
	return (substr);
}
