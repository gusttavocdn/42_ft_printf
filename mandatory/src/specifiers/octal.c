/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 22:24:48 by gusda-si          #+#    #+#             */
/*   Updated: 2023/10/01 22:25:13 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	fmt_octal(t_fmt_buffer *buffer, t_flags *flags, va_list args)
{
	char			*octal_str;
	unsigned int	number;

	number = va_arg(args, size_t);
	octal_str = ft_itoa_base_u(number, OCTAL);
	if (flags->has_hash)
		hash(buffer, flags);
	buffer->size += (int)ft_strlen(octal_str);
	ft_strlcat(buffer->data, octal_str, BUFFER_SIZE);
	if (flags->has_minus)
		minus(buffer, flags, (int)ft_strlen(octal_str));
	free(octal_str);
}
