/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 01:39:37 by gusda-si          #+#    #+#             */
/*   Updated: 2023/10/01 13:30:26 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	width(t_fmt_buffer *buffer, int len, char pad_char)
{
	while (len-- > 0)
		buffer->data[buffer->index++] = pad_char;
}
