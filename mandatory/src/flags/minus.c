/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:45:11 by gusda-si          #+#    #+#             */
/*   Updated: 2023/10/01 18:38:31 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	minus(t_fmt_buffer *buffer, t_flags *flags, int len)
{
	int	width;

	width = flags->width - len;
	if (flags->precision < 0)
	{
		while (width-- > 0)
			buffer->data[buffer->index++] = ' ';
	}
}

void	minus_string(t_fmt_buffer *buffer, t_flags *flags, int len)
{
	int	width;

	width = flags->width - len;
	while (width-- > 0)
		buffer->data[buffer->index++] = ' ';
}
