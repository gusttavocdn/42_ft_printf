/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:10:32 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/31 16:42:20 by gusda-si         ###   ########.fr       */
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

// Function declarations
/**
 * @brief This function can write a formatted string to the standard output.
 * For more info consult the manual (man 3 printf)
 */
int					ft_printf(const char *format, ...);
int					handle_just_specifier(char specifier, va_list args);
int					handle_flags(const char *str, va_list args,
						int *walked_bytes);
t_bool				is_specifier(char flag);
t_bool				is_flag(char flag);
char				*get_argument(t_specifiers specifier, va_list args);
void				init_flags(t_flags *flags);

// FLAGS APPLIERS
int	apply_flags(t_flags *flags, va_list args);
int					apply_hash(t_flags *flags);
int					apply_width(t_flags *flags, char *number,
						char padding_char);
int					apply_precision(t_flags *flags, char *number);
int					apply_plus(t_flags *flags);
int					apply_space(t_flags *flags);
char	*convert_specifier_to_str(t_specifiers specifier, va_list args);

#endif // FT_PRINTF_H
