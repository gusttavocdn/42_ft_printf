/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:10:32 by gusda-si          #+#    #+#             */
/*   Updated: 2023/09/03 14:05:04 by gusda-si         ###   ########.fr       */
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
# define SPECIFIERS "cspdiuxXob%"

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
	char			*data;
	int				index;
}					t_fmt_buffer;

int					ft_printf(const char *str, ...);
int	handle_flags_and_specifiers(t_fmt_buffer *buffer,
								const char *str,
								va_list args);
t_bool				is_specifier(char specifier);
t_bool				is_flag(char flag);
void	apply_flags_and_specifiers(t_fmt_buffer *buffer,
								t_flags *flags,
								va_list args);
void				apply_hex(t_fmt_buffer *buffer, t_flags *flags,
						va_list args);
void				apply_octal(t_fmt_buffer *buffer, t_flags *flags,
						va_list args);
void				hash(t_fmt_buffer *buffer, t_flags *flags);
void				plus(t_fmt_buffer *buffer, t_flags *flags);
void				apply_int(t_fmt_buffer *buffer, t_flags *flags,
						va_list args);
#endif // FT_PRINTF_H
