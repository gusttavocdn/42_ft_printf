/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:10:29 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/26 14:41:07 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_bool	it_is_a_flag(char flag)
{
	size_t	counter;

	counter = 0;
	while (FLAGS[counter] != '\0')
	{
		if (FLAGS[counter] == flag)
			return (TRUE);
		counter++;
	}
	return (FALSE);
}

t_bool	it_is_a_specifier(char flag)
{
	size_t	counter;

	counter = 0;
	while (CONVERSIONS[counter] != '\0')
	{
		if (CONVERSIONS[counter] == flag)
			return (TRUE);
		counter++;
	}
	return (FALSE);
}
