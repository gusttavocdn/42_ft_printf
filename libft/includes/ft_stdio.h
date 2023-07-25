/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdio.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 19:00:04 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/23 21:49:53 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDIO_H
# define FT_STDIO_H

// Standard Library headers
# include <stdlib.h>
# include <unistd.h>

// Function declarations

/**
 * @brief Outputs the char "c" to the given file descriptor
 *
 * @param c The char to output
 * @param fd the file descriptor on which to write
 */
ssize_t	ft_putchar_fd(char c, int fd);

/**
 * @brief Outputs the string "s" to the given file descriptor
 *
 * @param s The string to output
 * @param fd The file descriptor on which to write
 */
ssize_t	ft_putstr_fd(char *s, int fd);

/**
 * @brief Outputs the string "s" to the given file descriptor
 * followed by a newline.
 *
 * @param s The string to output
 * @param fd The file descriptor on which to write
 */
ssize_t	ft_putendl_fd(char *s, int fd);

/**
 * @brief Outputs the integer "n" to the given fd
 *
 * @param n The number to output
 * @param fd The file descriptor on which to write
 */
ssize_t	ft_putnbr_fd(long int n, int fd);

/**
 * @brief Outputs the integer "nbr" to the given fd
 * using the given "base" as the base for the conversion.
*/

ssize_t	ft_putnbr_base(long int nbr, char *base, int fd);

/**
 	@brief Reads a line from a file descriptor.
	@param fd File descriptor.
	@return A pointer to the line read from the file descriptor.
	@details This functions is capable of handle multiple fd at once.
*/
char	*ft_gnl(int fd);

#endif // FT_STDIO_H
