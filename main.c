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

	// Tests "-' flag for C specifier
//	og_result = printf("OG: %-1c\n", '0');
//	ft_result = ft_printf("FT: %-1c\n", '0');
//	printf("OG => %d\n", og_result);
//	printf("FT => %d\n", ft_result);
//
//	og_result = printf("OG: %-2c\n", '0');
//	ft_result = ft_printf("FT: %-2c\n", '0');
//	printf("OG => %d\n", og_result);
//	printf("FT => %d\n", ft_result);
//
//	og_result = printf("OG: %-3c\n", '0' - 256);
//	ft_result = ft_printf("FT: %-3c\n", '0' - 256);
//	printf("OG => %d\n", og_result);
//	printf("FT => %d\n", ft_result);
//
//	og_result = printf("OG: %-4c\n", '0' - 256);
//	ft_result = ft_printf("FT: %-4c\n", '0' - 256);
//	printf("OG => %d\n", og_result);
//	printf("FT => %d\n", ft_result);

//	og_result = printf("OG: %-1c %-2c %-3c\n", '0', 0, '1');
//	ft_result = ft_printf("FT: %-1c %-2c %-3c\n", '0', 0, '1');
//	printf("OG => %d\n", og_result);
//	printf("FT => %d\n", ft_result);
//

	// Tests "-" flag for S specifier
//	og_result = printf("OG: %1s\n", "");
//	ft_result = ft_printf("FT: %1s\n", "");
//	printf("OG => %d\n", og_result);
//	printf("FT => %d\n", ft_result);
//
//	og_result = printf("OG: %-1s\n", "");
//	ft_result = ft_printf("FT: %-1s\n", "");
//	printf("OG => %d\n", og_result);
//	printf("FT => %d\n", ft_result);
//
//	og_result = printf("OG: %-2s\n", "");
//	ft_result = ft_printf("FT: %-2s\n", "");
//	printf("OG => %d\n", og_result);
//	printf("FT => %d\n", ft_result);

 	// Tests "-" flag for P specifier
//	 og_result = printf("%2p\n", (void *)-1);
//	 ft_result = ft_printf("%2p\n", (void *)-1);
//	 printf("OG => %d\n", og_result);
//	 printf("FT => %d\n", ft_result);
//
//	og_result = printf("OG: %-2p\n", (void *)-1);
//	ft_result = ft_printf("FT: %-2p\n", (void *)-1);
//	printf("OG => %d\n", og_result);
//	printf("FT => %d\n", ft_result);

//	og_result = printf("OG: %-9p %-10p\n", (void *)LONG_MIN, (void *)LONG_MAX);
//	ft_result = ft_printf("FT: %-9p %-10p\n", (void *)LONG_MIN, (void *)
//	LONG_MAX);
//	printf("OG => %d\n", og_result);
//	printf("FT => %d\n", ft_result);
//
//	og_result = printf("OG: %-13p %-14p\n", (void *)ULONG_MAX, (void *)
//	-ULONG_MAX);
//	ft_result = ft_printf("FT: %-13p %-14p\n", (void *)ULONG_MAX, (void *)
//	-ULONG_MAX);
//	printf("OG => %d\n", og_result);
//	printf("FT => %d\n", ft_result);
//
//	og_result = printf("OG: %-2p\n", (void *)15);
//	ft_result = ft_printf("FT: %-2p\n", (void *)15);
//	printf("OG => %d\n", og_result);
//	printf("FT => %d\n", ft_result);

//	og_result = printf("OG: %-4p\n", (void *)17);
//	ft_result = ft_printf("FT: %-4p\n", (void *)17);
//	printf("OG => %d\n", og_result);
//	printf("FT => %d\n", ft_result);

	og_result = printf("OG: %-1p %-2p\n", (void *)0, (void*)0);
	ft_result = ft_printf("FT: %-1p %-2p\n", (void *)0, (void*)0);
	printf("OG => %d\n", og_result);
	printf("FT => %d\n", ft_result);

	return 0;
}
