/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:13:15 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/27 03:10:36 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	main(void)
{
	int	my_result;
	int	printf_result;
//	char *str = "Hello World!";

	my_result = ft_printf("%#x\n", 42);
	printf_result = printf("%#x\n", 42);
	return (0);
}
