/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:18:44 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/31 16:43:34 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf_bonus.h"

int	apply_space(t_flags *flags)
{
	if (flags->specifier == 'd' || flags->specifier == 'i')
		return ((int)(ft_putchar_fd(' ', STDOUT_FILENO)));
	else
		return (0);
}
