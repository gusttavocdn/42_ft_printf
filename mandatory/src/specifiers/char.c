/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/* char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023-10-01 22:22:13 by gusda-si          #+#    #+#             */
/*   Updated: 2023-10-01 22:22:13 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	fmt_char(t_fmt_buffer *buffer, t_flags *flags, va_list args)
{
	char	c;

	c = va_arg(args, int);
	if (!flags->has_minus)
		width(buffer, flags->width - 1, ' ');
	buffer->data[buffer->index] = c;
	buffer->index++;
	if (flags->has_minus)
		minus(buffer, flags, 1);
}
