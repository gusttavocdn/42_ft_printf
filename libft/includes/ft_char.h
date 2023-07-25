/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 19:00:01 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/23 21:42:23 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHAR_H
# define FT_CHAR_H

// Function declarations

/**
 * @brief This functions verify if a char is character from a-z or A-Z
 * @return Returns 1 if a char is character from a-z or A-Z or 0 otherwise
 */
int	ft_isalpha(int c);

/**
 * @brief This functions verify if a char is a digit from 0-9
 * @return Returns 1 if a char is character from 0-9 or 0 otherwise
 */
int	ft_isdigit(int c);

/**
 * @brief This functions verify if a char is alphanumeric
 * @return Returns 1 if a char is alphanumeric or 0 otherwise
 */
int	ft_isalnum(int c);

/**
 * @brief This functions verify if a char is ascii
 * @return Returns 1 if a char is ascii or 0 otherwise
 */
int	ft_isascii(int c);

/**ato
 * @brief This functions verify if a char is printable
 * @return Returns 1 if a char is printable or 0 otherwise
 */
int	ft_isprint(int c);

/**
 * @brief This functions converts a upper case character
 * to lower case
 * @param c character to be convert
 * @return Returns the converted char
 */
int	ft_toupper(int c);

/**
 * @brief This functions converts a lower case character
 * to upper case
 * @param c character to be convert
 * @return Returns the converted char
 */
int	ft_tolower(int c);

/**
 * @brief This functions verify if a char is a space
*/
int	ft_isspace(int c);

#endif // FT_CHAR_H
