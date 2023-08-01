/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:49:13 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/31 16:32:44 by gusda-si         ###   ########.fr       */
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

	og_result = printf("OG: %-s\n", "-");
	ft_result = ft_printf("FT: %-s\n", "-");
	printf("OG: %d\n", og_result);
	printf("FT: %d\n", ft_result);

	og_result = printf("OG: %-3s %-4s\n", " - ", "");
	ft_result = ft_printf("FT: %-3s %-4s\n", " - ", "");
	printf("OG: %d\n", og_result);
	printf("FT: %d\n", ft_result);

//	og_result = printf("OG: %.1s %.2s %.3s %.4s\n", " - ", "", "4", "");
//	ft_result = ft_printf("FT: %.1s %.2s %.3s %.4s\n", " - ", "", "4", "");
//	printf("OG: %d\n", og_result);
//	printf("FT: %d\n", ft_result);
//
//	og_result = printf("OG: %.2s %.3s %.4s %.5s %.1s", " - ", "", "4", "", "2 ");
//	printf("\n");
//	ft_result = ft_printf("FT: %.2s %.3s %.4s %.5s %.1s", " - ", "", "4", "", "2 ");
//	printf("\n");
//	printf("OG: %d\n", og_result);
//	printf("FT: %d\n", ft_result);

	return 0;
}
