/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 21:18:06 by gusda-si          #+#    #+#             */
/*   Updated: 2023/09/30 01:13:46 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/includes/ft_printf.h"
#include <limits.h>
#include <stdio.h>

int	main(void)
{
	int	og;
	int	ft;

	og = printf("%-130d\n", 1000);
	ft = ft_printf("%-130d\n", 1000);

	printf("OG: %d\nFT: %d\n", og, ft);

	og = printf("%-130x\n", -1000);
	ft = ft_printf("%-130x\n", -1000);

	printf("OG: %d\nFT: %d\n", og, ft);

	og = printf("%-10X\n", 1000);
	ft = ft_printf("%-10X\n", 1000);

	printf("OG: %d\nFT: %d\n", og, ft);
	return (0);
}
