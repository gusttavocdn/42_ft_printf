/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_flag_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:37:00 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/31 16:43:36 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf_bonus.h"

t_bool	is_flag(char flag)
{
	size_t	counter;

	counter = 0;
	while (FLAGS[counter] != '\0')
	{
		if (FLAGS[counter] == flag)
			return (my_true);
		counter++;
	}
	return (my_false);
}
