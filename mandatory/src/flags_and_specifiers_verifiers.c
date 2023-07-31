/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_and_specifiers_verifiers.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:10:29 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/31 15:37:35 by gusda-si         ###   ########.fr       */
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