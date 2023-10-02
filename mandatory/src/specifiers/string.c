/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 22:25:38 by gusda-si          #+#    #+#             */
/*   Updated: 2023/10/01 22:25:46 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	fmt_str(t_fmt_buffer *buffer, t_flags *flags, va_list args)
{
	char	*string;
	int		len;

	string = va_arg(args, char *);
	if (!string && (flags->precision > -1 && flags->precision < 6))
		return ;
	if (!string)
		string = "(null)";
	len = (int)ft_strlen(string);
	if (len <= 0)
		return ;
	if (!flags->has_minus)
	{
		if (flags->precision != -1 && flags->precision < len)
			width(buffer, flags->width - flags->precision, ' ');
		else
			width(buffer, flags->width - len, ' ');
	}
	if (flags->precision != -1 && flags->precision < len)
		buffer->size += flags->precision;
	else
		buffer->size += len;
	ft_strncat(buffer->data, string, (flags->precision));
	if (flags->has_minus)
		minus_string(buffer, flags, len);
}
