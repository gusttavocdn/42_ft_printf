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

#include "../includes/ft_printf_bonus.h"

static char *handle_c_specifier(va_list args);
static char*	handle_p_specifier(va_list args);

char	*get_argument(t_specifiers specifier, va_list args)
{
	if (specifier == c)
		return (handle_c_specifier(args));
	if (specifier == s)
		return (ft_strdup(va_arg(args, char *)));
	if (specifier == d || specifier == i)
		return (ft_itoa(va_arg(args, int)));
	if (specifier == x)
		return (ft_itoa_base_u(va_arg(args, unsigned int), HEX_LOWER));
	if (specifier == X)
		return (ft_itoa_base_u(va_arg(args, unsigned int), HEX_UPPER));
	if (specifier == percent)
		return (ft_strdup("%"));
	if (specifier == u)
		return (ft_itoa_base_u(va_arg(args, unsigned int), DECIMAL));
	if (specifier == p)
		return (handle_p_specifier(args));
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


static char *handle_c_specifier(va_list args)
{
	char	*str;
	char	c;

	c = va_arg(args, int);
	str = ft_calloc(2, sizeof(char));
	str[0] = c;
	return (str);
}

static char*	handle_p_specifier(va_list args)
{
	char	*str;
	char 	*itoa_pointer;
	unsigned long pointer;

	pointer = va_arg(args, unsigned long);
	if (pointer == 0)
		return (ft_strdup("(nil)"));
	itoa_pointer = ft_itoa_base_u(pointer, HEX_LOWER);
	if (itoa_pointer == NULL)
		return  (ft_strdup("(nil)"));
	str = ft_strjoin("0x", itoa_pointer);
	if (str == NULL)
	{
		free(itoa_pointer);
		return (ft_strdup("(nil)"));
	}
	free(itoa_pointer);
	return (str);
}
