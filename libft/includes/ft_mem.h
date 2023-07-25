/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:33:54 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/18 11:59:30 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEM_H
# define FT_MEM_H

// Standard Library headers
# include <stdlib.h>

// Function declarations

/**
 * @brief This function erases some memory area. The area to be
 * deleted is passed as n bytes. The area will be filled with NULL (0)
 * @param s The area to be erased
 * @param n The number of bytes to be erased
 */
void	ft_bzero(void *s, size_t n);

/**
 * @brief This functions allocate an amount of memory and initialize
 * with 0.
 * @param nmemb The quantity of elements to allocate
 * @param size The size of each individual element
 * @return Returns a pointer to the allocated memory.
 * If fails, returns NULL.
 */
void	*ft_calloc(size_t nmemb, size_t size);

/**
 * @brief This functions fill the n bytes of memory area with C char
 * @param s The memory area that will be filled
 * @param c The char to fill the memory with.
 */
void	*ft_memset(void *s, int c, size_t n);

/**
 * @brief This function copy a memory area to other memory area.
 * Don't use if the memory area might overlap.
 * In this case, use memmove instead.
 * @param dest dest area to receive the copy
 * @param src source area to copy
 * @param n n bytes that will be copied to dest
 * @return returns a void pointer to dest.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * @brief This function copies n bytes from memory area src to dest.
 * The memory area may overlap.
 *
 * @param dest Memory area dest for the copied bytes.
 * @param src Memory area to copy from.
 * @param n N bytes to copy.
 * @return Returns a void pointer to dest
 */
void	*ft_memmove(void *dest, const void *src, size_t n);

/**
 * @brief This functions scans until n bytes of a memory area searching for
 * The first instance of c
 * @param str Memory area to looking from
 * @param c Byte to looking for
 * @param n Until bytes we will scan
 * @return Returns a void pointer to the first instance of c or NULL if
 * doesn't found.
 */
void	*ft_memchr(const void *str, int c, size_t n);

/**
 * @brief This function compares two memory area until n bytes
 */
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * @brief This function swaps two memory areas
 * @param a First memory area
 * @param b Second memory area
 * @param size Size of each memory area
 */
void	ft_swap(void *a, void *b, size_t size);

#endif // FT_MEM_H
