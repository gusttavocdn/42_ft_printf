/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_specifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 23:17:08 by gusda-si          #+#    #+#             */
/*   Updated: 2023/10/01 14:58:27 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_bool	is_specifier(char specifier)
{
	size_t	counter;

	counter = 0;
	while (SPECIFIERS[counter] != '\0')
	{
		if (SPECIFIERS[counter] == specifier)
			return (my_true);
		counter++;
	}
	return (my_false);
}
