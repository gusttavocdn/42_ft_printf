/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 21:18:06 by gusda-si          #+#    #+#             */
/*   Updated: 2023/09/02 23:00:33 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/includes/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int og, ft;

	ft = ft_printf("Hello World!dsadasda\n");
	og = printf("Hello World!dsadasda\n");

	printf("OG: %d\nFT: %d\n", og, ft);
	return 0;
}
