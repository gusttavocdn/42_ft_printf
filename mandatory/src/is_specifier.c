/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_specifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 23:17:08 by gusda-si          #+#    #+#             */
/*   Updated: 2023/09/02 23:20:02 by gusda-si         ###   ########.fr       */
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
			return (true);
		counter++;
	}
	return (false);
}
