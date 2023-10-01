/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 23:18:42 by gusda-si          #+#    #+#             */
/*   Updated: 2023/10/01 14:58:03 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"


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
