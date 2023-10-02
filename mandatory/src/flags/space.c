/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:03:50 by gusda-si          #+#    #+#             */
/*   Updated: 2023/09/03 17:23:44 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	space(t_fmt_buffer *buffer, t_flags *flags)
{
	if (flags->specifier == d || flags->specifier == i)
	{
		if (flags->has_plus)
			return ;
		if (flags->has_minus)
			return ;
		if (flags->has_zero)
			return ;
		if (flags->has_hash)
			return ;
		if (flags->width > 0)
			return ;
		buffer->data[buffer->size++] = ' ';
	}
}
