/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 21:18:06 by gusda-si          #+#    #+#             */
/*   Updated: 2023/10/01 23:57:23 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/includes/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	// char	*null_str;

	int og, ft;
	// char *c;
	// null_str = NULL;
	// c = malloc(sizeof(char));
	og = printf("the address is %8p", (void *)0);
	printf("\n");
	ft = ft_printf("the address is %8p", (void *)0);
	printf("\n\nog: %d\nft: %d\n", og, ft);
	return (0);
}
