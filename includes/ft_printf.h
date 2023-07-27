/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:10:32 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/26 14:13:07 by gusda-si         ###   ########.fr       */
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
# define CONVERSIONS "cspdiuxX%"
# define HEX_LOWER_BASE "0123456789abcdef"
# define HEX_UPPER_BASE "0123456789ABCDEF"

// Enum declarations

// Macro declarations

// Struct declarations

// Function declarations

/**
 * @brief This function can write a formatted string to the standard output.
 * For more info consult the manual (man 3 printf)
*/
int	ft_printf(const char *format, ...);
int	handle_specifier(char specifier, va_list args);

#endif // FT_PRINTF_H