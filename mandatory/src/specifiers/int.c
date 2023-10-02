/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 22:24:25 by gusda-si          #+#    #+#             */
/*   Updated: 2023/10/01 22:25:27 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	fmt_int(t_fmt_buffer *buffer, t_flags *flags, va_list args)
{
	char	*int_str;
	int		number;
	int		len;

	number = va_arg(args, int);
	int_str = ft_itoa(number);
	len = (int)ft_strlen(int_str);
	if (flags->has_plus && number >= 0)
		plus(buffer);
	width(buffer, flags->precision - len, '0');
	if (flags->has_space && number >= 0)
		space(buffer, flags);
	if (flags->has_zero && !flags->has_minus)
		zero(buffer, flags, (int)ft_strlen(int_str));
	buffer->index += (int)ft_strlen(int_str);
	ft_strlcat(buffer->data, int_str, BUFFER_SIZE);
	if (flags->has_minus)
		minus(buffer, flags, (int)ft_strlen(int_str));
	width(buffer, flags->width - flags->precision - 1, ' ');
	free(int_str);
}
