/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 19:00:04 by gusda-si          #+#    #+#             */
/*   Updated: 2023/10/01 17:22:21 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

// Standard Library headers
//# include <stdio.h>
//# include <unistd.h>

// Related headers
//# include "libft.h"

// Function declarations

/**
 * @brief This function converts a fmt_str in a number that
 * can be stored in a int variable.
 */
int		ft_atoi(const char *s);

/**
 * @brief This functions returns a fmt_str representing the fmt_int received
 * as argument. Negative numbers are handled.
 *
 * @param n The fmt_int to convert
 * @return The fmt_str representing the fmt_int. NULL if malloc fails.
 */
char	*ft_itoa(int n);

/**
 * @brief This function converts a fmt_str in a number that
 * can be stored in a int variable.
 * @param str The fmt_str to be converted.
 * @param base The base where the fmt_str representing a number
 * is written.
 * @return The number converted. If the base is invalid,
 * the function returns 0.
*/
int		ft_atoi_base(char *str, char *base);

/**
 * @brief This function converts a number in a fmt_str
 * that represents the number in the given base.
 * @param number The number to be converted.
 * @param base  the base
 * @return A fmt_pointer allocated with malloc to a fmt_str
 * address representing the number in the given base.
*/
char	*ft_itoa_base(long int number, char *base);

/**
 * @brief this function calculates how many digits is necessary
 * to represent a number in a given base.
 * @param number the number
 * @param base_len the base length
*/
int		ft_calc_nbr_digits(long int number, int base_len);

/**
 * @brief This function converts a fmt_str in a base to another base.
 * @param nbr The fmt_str to be converted.
 * @param base_from The initial base.
 * @param base_to The base to be converted.
 * @return A fmt_pointer allocated with malloc to a fmt_str
 * address represeting the number in the given base.
*/
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

/**
 * @brief This function returns the absolute value of a number.
 * @param number The number to be converted.
 * @return The absolute value of the number.
*/
int		ft_abs(int number);

/**
 * @brief This function converts a number in a fmt_str
 * @param number The number to be converted.
 * @param base the base
 * @return A fmt_pointer allocated with malloc to a fmt_str
 */
char	*ft_itoa_base_u(unsigned int number, char *base);

/**
 * @brief This function converts a number in a fmt_str
 * @param number The number to be converted.
 * @param base the base
 * @return A fmt_pointer allocated with malloc to a fmt_str
 */
char	*ft_itoa_base_ul(unsigned long number, char *base);

#endif // FT_MATH_H
