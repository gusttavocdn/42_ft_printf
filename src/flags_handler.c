/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_flag_handle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:10:06 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/26 14:10:15 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void verify_what_flags_i_have(t_flags *flags, const char *str);

void handle_flags(const char *str, va_list args)
{
	t_flags flags;
	(void)args;
	verify_what_flags_i_have(&flags, str);
}

static void verify_what_flags_i_have(t_flags *flags, const char *str)
{

	while (!it_is_a_specifier(*str) && *str != '\0')
	{
		if (*str == '#')
			flags->has_hash = TRUE;
		if (*str == '-')
			flags->has_minus = TRUE;
		if (*str == '+')
			flags->has_plus = TRUE;
		if (*str == ' ')
			flags->has_space = TRUE;
		if (*str == '0')
			flags->has_zero = TRUE;
		str++;
	}
}
