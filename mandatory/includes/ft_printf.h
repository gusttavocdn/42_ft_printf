/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:10:32 by gusda-si          #+#    #+#             */
/*   Updated: 2023/09/02 22:47:08 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// Related headers
# include "../../libft/includes/libft.h"
# include <stdarg.h>

// Enum declarations
typedef enum e_specifiers
{
	c = 'c',
	s = 's',
	p = 'p',
	i = 'i',
	u = 'u',
	x = 'x',
	X = 'X',
	d = 'd',
	o = 'o',
	b = 'b',
	percent = '%',
}					t_specifiers;

// Macro declarations
# define FLAGS "-0.#+ "
# define SPECIFIERS "cspdiuxX%"

// Struct declarations
typedef struct s_flags
{
	t_bool			has_hash;
	t_bool			has_zero;
	t_bool			has_space;
	t_bool			has_plus;
	t_bool			has_minus;
	t_specifiers	specifier;
	int				width;
	int				precision;
}					t_flags;

typedef struct s_fmt_buffer
{
	char	*data;
	int		index;
}				t_fmt_buffer;

int ft_printf(const char *str, ...);

#endif // FT_PRINTF_H
