/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_initializer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 09:00:10 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/29 19:37:57 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*get_argument(t_specifiers specifier, va_list args)
{
	if (specifier == c)
		return (ft_itoa(va_arg(args, int)));
	if (specifier == s)
		return (ft_strdup(va_arg(args, char *)));
	if (specifier == d || specifier == i)
		return (ft_itoa(va_arg(args, int)));
	if (specifier == x)
		return (ft_itoa_base(va_arg(args, long int), HEX_LOWER));
	if (specifier == X)
		return (ft_itoa_base(va_arg(args, long int), HEX_UPPER));
	if (specifier == percent)
		return (ft_strdup("%"));
	if (specifier == u)
		return (ft_itoa(va_arg(args, unsigned int)));
	if (specifier == p)
		return (ft_itoa(va_arg(args, unsigned long)));
	return (NULL);
}

void	init_flags(t_flags *flags)
{
	flags->has_minus = my_false;
	flags->has_hash = my_false;
	flags->has_zero = my_false;
	flags->has_space = my_false;
	flags->has_plus = my_false;
	flags->width = -1;
	flags->precision = -1;
}
