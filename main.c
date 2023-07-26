/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:13:15 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/26 14:41:05 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	main(void)
{
	int	my_result;
	int	printf_result;

	my_result = ft_printf("Gustavo %d\n", 40);
	printf_result = printf("Gustavo %d\n", 40);
	my_result = ft_printf("%s\n", "Gustavo");
	printf_result = printf("%s\n", "Gustavo");
	my_result = ft_printf("%c\n", 'a');
	printf_result = printf("%c\n", 'a');
	my_result = ft_printf("%d and %i\n", 20, 10);
	printf_result = printf("%d and %i\n", 20, 10);
	my_result = ft_printf("%x and %x and %%\n", 20, 10);
	printf_result = ft_printf("%x and %x and %%\n", 20, 10);
	return (0);
}
