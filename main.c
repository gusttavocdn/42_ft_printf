/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 21:18:06 by gusda-si          #+#    #+#             */
/*   Updated: 2023/10/01 17:15:32 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/includes/ft_printf.h"
#include <limits.h>
#include <stdio.h>

int	main(void)
{
	// char	*null_str;

	int og, ft;
	// null_str = NULL;
	og = printf("The NULL macro represents the %p address", ((void*)0));;
	printf("\n");
	ft = ft_printf("The NULL macro represents the %p address", ((void*)0));
	printf("\n\nog: %d\nft: %d\n", og, ft);
	return (0);
}
