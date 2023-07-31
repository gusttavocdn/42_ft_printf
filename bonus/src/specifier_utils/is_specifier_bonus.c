/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_specifier_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:37:53 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/31 16:42:43 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf_bonus.h"

t_bool	is_specifier(char flag)
{
	size_t	counter;

	counter = 0;
	while (SPECIFIERS[counter] != '\0')
	{
		if (SPECIFIERS[counter] == flag)
			return (my_true);
		counter++;
	}
	return (my_false);
}
