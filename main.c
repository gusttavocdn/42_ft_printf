/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 21:18:06 by gusda-si          #+#    #+#             */
/*   Updated: 2023/10/01 18:13:53 by gusda-si         ###   ########.fr       */
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
	og = printf("%--4.1s %s %------------------9.3s of %s of %-5.7s", "for", "the", "goooood", "aaall", "us");
	printf("\n");
	ft = ft_printf("%--4.1s %s %------------------9.3s of %s of %-5.7s",
				   "for", "the", "goooood", "aaall", "us");
	printf("\n\nog: %d\nft: %d\n", og, ft);
	return (0);
}
