/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:16:22 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/31 16:43:35 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf_bonus.h"

int	apply_plus(t_flags *flags)
{
	if (flags->specifier == 'd' || flags->specifier == 'i')
		return ((int)(ft_putchar_fd('+', STDOUT_FILENO)));
	else
		return (0);
}
