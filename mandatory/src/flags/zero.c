/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:28:06 by gusda-si          #+#    #+#             */
/*   Updated: 2023/09/03 17:41:49 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	zero(t_fmt_buffer *buffer, t_flags *flags, int number_len)
{
	int	width;

	width = flags->width - number_len;
	if (flags->precision < 0)
	{
		while (width-- > 0)
			buffer->data[buffer->index++] = '0';
	}
}
