/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_ptrs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:58:45 by gusda-si          #+#    #+#             */
/*   Updated: 2023/09/30 01:07:43 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_swap_ptrs(void **old_ptr, void *new_ptr)
{
	void	*temp;

	temp = *old_ptr;
	*old_ptr = new_ptr;
	free(temp);
	temp = NULL;
}
