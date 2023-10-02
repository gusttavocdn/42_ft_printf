/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 12:59:24 by gusda-si          #+#    #+#             */
/*   Updated: 2023/10/01 14:50:26 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	hash(t_fmt_buffer *buffer, t_flags *flags)
{
	buffer->data[buffer->size++] = '0';
	if (flags->specifier == x || flags->specifier == X)
		buffer->data[buffer->size++] = flags->specifier;
}
