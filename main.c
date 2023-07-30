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

#include "includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

// The overall syntax of a conversion specification is:
//           %[$][flags][width][.precision][length modifier]conversion

int main(void)
{
	int ft_result;
	int og_result;

//	 og_result = printf("OG: 20 in hexadecimal %#x\n", 20);
//	 ft_result = ft_printf("FT: 20 in hexadecimal %#x\n", 20);
//	 printf("OG => %d\n", og_result);
//	 printf("FT => %d\n", ft_result);
//
//	og_result = printf("OG: -20 in hexadecimal %x\n", -20);
//	ft_result = ft_printf("FT: -20 in hexadecimal %x\n", -20);
//	printf("OG => %d\n", og_result);
//	printf("FT => %d\n", ft_result);
//
//	og_result = printf("OG: -20 in hexadecimal %#x\n", -1);
//	ft_result = ft_printf("FT: -20 in hexadecimal %#x\n", -1);
//	printf("OG => %d\n", og_result);
//	printf("FT => %d\n", ft_result);
//
//	og_result = printf("OG: 0 in hexadecimal %#x\n", 0);
//	ft_result = ft_printf("FT: 0 in hexadecimal %#x\n", 0);
//	printf("OG => %d\n", og_result);
//	printf("FT => %d\n", ft_result);
////
//
//	og_result = printf("OG: %#X\n", 20);
//	ft_result = ft_printf("FT: %#X\n", 20);
//	printf("OG => %d\n", og_result);
//	printf("FT => %d\n", ft_result);

//	og_result = printf("OG: 21321 in hexadecimal %#.10X\n", 21321);
//	ft_result = ft_printf("FT: 21321 in hexadecimal %#.10X\n", 21321);
//	printf("OG => %d\n", og_result);
//	printf("FT => %d\n", ft_result);

	// Tests with only precision

//	og_result = printf("OG: 21321 in decimal %.10d\n", 21321);
//	ft_result = ft_printf("FT: 21321 in decimal %#.10d\n", 21321);
//	printf("OG => %d\n", og_result);
//	printf("FT => %d\n", ft_result);
//
//	og_result = printf("OG: -200 in decimal %.10d\n", -200);
//	ft_result = ft_printf("FT: -200 in decimal %#.10d\n", -200);
//	printf("OG => %d\n", og_result);
//	printf("FT => %d\n", ft_result);
//
//	og_result = printf("OG: 200 in decimal %.1d\n", 200);
//	ft_result = ft_printf("FT: 200 in decimal %#.1d\n", 200);
//	printf("OG => %d\n", og_result);
//	printf("FT => %d\n", ft_result);
//
//	og_result = printf("OG: 200 in decimal %.d\n", 200);
//	ft_result = ft_printf("FT: 200 in decimal %#.d\n", 200);
//	printf("OG => %d\n", og_result);
//	printf("FT => %d\n", ft_result);

// Test precision with width

//	og_result = printf("OG: 143 in decimal %10.10d\n", 143);
//	ft_result = ft_printf("FT: 143 in decimal %10.10d\n", 143);
//	printf("OG => %d\n", og_result);
//	printf("FT => %d\n", ft_result);

//	og_result = printf("OG: -143 in decimal %100.10d\n", -143);
//	ft_result = ft_printf("FT: -143 in decimal %100.10d\n", -143);
//	printf("OG => %d\n", og_result);
//	printf("FT => %d\n", ft_result);
//
//	og_result = printf("OG: -143 in decimal %11.10d\n", -143);
//	ft_result = ft_printf("FT: -143 in decimal %11.10d\n", -143);
//	printf("OG => %d\n", og_result);
//	printf("FT => %d\n", ft_result);
//
//	og_result = printf("OG: 3212 in hexadecimal %11.10x\n", 3212);
//	ft_result = ft_printf("FT: 3212 in hexadecimal %11.10x\n", 3212);
//	printf("OG => %d\n", og_result);
//	printf("FT => %d\n", ft_result);
//
//	og_result = printf("OG: 3212 in hexadecimal %11.101x\n", 3212);
//	ft_result = ft_printf("FT: 3212 in hexadecimal %11.101x\n", 3212);
//	printf("OG => %d\n", og_result);
//	printf("FT => %d\n", ft_result);

// Tests with O flag

//	og_result = printf("OG: 20 in decimal %01d\n", -20);
//	printf("OG => %d\n", og_result);
//	ft_result = ft_printf("FT: 20 in decimal %01d\n", -20);
//	printf("FT => %d\n", ft_result);

// Test with + flag

	og_result = printf("OG: 20 in decimal %+d\n", 20);
	printf("OG => %d\n", og_result);
	ft_result = ft_printf("FT: 20 in decimal %+d\n", 20);
	printf("FT => %d\n", ft_result);

	og_result = printf("OG: 20 in decimal %+d\n", -20);
	printf("OG => %d\n", og_result);
	ft_result = ft_printf("FT: 20 in decimal %+d\n", -20);
	printf("FT => %d\n", ft_result);


	og_result = printf("OG: 20 in decimal %+43.10d\n", 20);
	printf("OG => %d\n", og_result);
	ft_result = ft_printf("FT: 20 in decimal %+43.10d\n", 20);
	printf("FT => %d\n", ft_result);

	return 0;
}
