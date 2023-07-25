/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:26:03 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/18 17:10:53 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_swap(void *a, void *b, size_t size)
{
	void	*temp;

	temp = malloc(size);
	ft_memcpy(temp, a, size);
	ft_memcpy(a, b, size);
	ft_memcpy(b, temp, size);
	free(temp);
}
