/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 12:59:24 by gusda-si          #+#    #+#             */
/*   Updated: 2023/09/03 14:04:30 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	hash(t_fmt_buffer *buffer, t_flags *flags)
{
	buffer->data[buffer->index++] = '0';
	if (flags->specifier == x || flags->specifier == X)
		buffer->data[buffer->index++] = flags->specifier;
}