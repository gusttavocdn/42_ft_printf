/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 10:39:37 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/18 08:38:49 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_bzero(void *s, size_t n)
{
	t_byte_u	*memory_addr;

	memory_addr = (t_byte_u *)s;
	while (n--)
		*memory_addr++ = '\0';
}
