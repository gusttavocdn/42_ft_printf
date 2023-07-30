/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:10:32 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/29 11:16:56 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// Standard Library headers
//# include <stdio.h>
//# include <unistd.h>

// Related headers
# include "../libft/includes/libft.h"
# include <stdarg.h>
# include <stdio.h>

// Constants
# define FLAGS "-0.#+ "
# define SPECIFIERS "cspdiuxX%"

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
	percent = '%',
}					t_specifiers;

// Macro declarations

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

// Function declarations

/**
 * @brief This function can write a formatted string to the standard output.
 * For more info consult the manual (man 3 printf)
*/
int					ft_printf(const char *format, ...);
int					handle_with_just_specifier(char specifier, va_list args);
int					handle_with_flags(const char *str, va_list args,
						int *walked_bytes, int bytes_printed_so_far);
t_bool				it_is_a_specifier(char flag);
t_bool				it_is_a_flag(char flag);
int					apply_prefix(t_flags *flags, char *number);
int					apply_width(t_flags *flags, char *number,
						char padding_char);
char				*get_argument(t_specifiers specifier, va_list args);
void				init_flags(t_flags *flags);

#endif // FT_PRINTF_H
