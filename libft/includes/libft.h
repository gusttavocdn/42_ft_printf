/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 23:48:40 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/23 21:49:54 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

// Standard Library headers
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

// Related headers
# include "ft_char.h"
# include "ft_math.h"
# include "ft_mem.h"
# include "ft_stdio.h"
# include "ft_strings.h"

// Constants
# define TRUE 1
# define FALSE 0
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define ULONG_MAX 18446744073709551615UL
# define NULL_BYTE 1
# define BUFFER_SIZE 4096

// Types

// Unsigned byte (8 bits)
typedef uint8_t		t_byte_u;

// Unsigned 2 bytes (16 bits)
typedef uint16_t	t_2byte_u;

// Unsigned 4 bytes (32 bits)
typedef uint32_t	t_4byte_u;

// Unsigned 8 bytes (64 bits)
typedef uint64_t	t_8byte_u;

// Signed byte (8 bits)
typedef int8_t		t_byte_i;

// Signed 2 bytes (16 bits)
typedef int32_t		t_2byte_i;

// Signed 4 bytes (32 bits)
typedef int32_t		t_4byte_i;

// Signed 8 bytes (64 bits)
typedef int64_t		t_8byte_i;

// Enum to representing boolean values
typedef enum e_bool
{
	true = TRUE,
	false = FALSE,
}					t_bool;

#endif
