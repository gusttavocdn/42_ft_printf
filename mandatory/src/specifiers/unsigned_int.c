/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 22:26:16 by gusda-si          #+#    #+#             */
/*   Updated: 2023/10/01 22:26:22 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	fmt_unsigned_int(t_fmt_buffer *buffer, t_flags *flags, va_list args)
{
	char	*unsigned_str;
	int		number;
	int		len;

	number = va_arg(args, unsigned int);
	unsigned_str = ft_itoa_base_u(number, DECIMAL);
	len = (int)ft_strlen(unsigned_str);
	if (flags->has_plus && number >= 0)
		plus(buffer);
	width(buffer, flags->precision - len, '0');
	if (flags->has_space && number >= 0)
		space(buffer, flags);
	if (flags->has_zero && !flags->has_minus)
		zero(buffer, flags, (int)ft_strlen(unsigned_str));
	buffer->index += (int)ft_strlen(unsigned_str);
	ft_strlcat(buffer->data, unsigned_str, BUFFER_SIZE);
	if (flags->has_minus)
		minus(buffer, flags, (int)ft_strlen(unsigned_str));
	width(buffer, flags->width - flags->precision - 1, ' ');
	free(unsigned_str);
}
