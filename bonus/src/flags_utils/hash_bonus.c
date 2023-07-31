/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:58:09 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/31 16:43:37 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf_bonus.h"

int	apply_hash(t_flags *flags)
{
	if (flags->specifier == x)
		return ((int)(ft_putstr_fd("0x", STDOUT_FILENO)));
	else
		return ((int)(ft_putstr_fd("0X", STDOUT_FILENO)));
}
