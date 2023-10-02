/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 22:26:51 by gusda-si          #+#    #+#             */
/*   Updated: 2023/10/01 22:26:58 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	fmt_percent(t_fmt_buffer *buffer, t_flags *flags)
{
	buffer->data[buffer->size++] = percent;
	if (flags->has_minus)
		minus(buffer, flags, 1);
}
