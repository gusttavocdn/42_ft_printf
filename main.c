/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:49:13 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/29 21:33:45 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

// The overall syntax of a conversion specification is:
//           %[$][flags][width][.precision][length modifier]conversion

int main(void)
{
	int ft_result;
	int og_result;

	// Tests for '-' flag i u specifier
	og_result = printf("OG: %-2u\n", -1);
	ft_result = ft_printf("FT: %-2u\n", -1);
	printf("OG: %d\n", og_result);
	printf("FT: %d\n", ft_result);

	og_result = printf("OG: %-2u\n", -10);
	ft_result = ft_printf("FT: %-2u\n", -10);
	printf("OG: %d\n", og_result);
	printf("FT: %d\n", ft_result);

	return 0;
}
