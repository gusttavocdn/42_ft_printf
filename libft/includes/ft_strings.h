/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 21:31:52 by gusda-si          #+#    #+#             */
/*   Updated: 2023/10/01 13:26:46 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRINGS_H
# define FT_STRINGS_H

// Standard Library headers
# include <stddef.h>

// Function declarations
/**
 * @brief Concatenate two strings and return the size of the result.
 * The concatenation is always null terminated.
 * @param dst The buffer where the final concatenation will be stored
 * @param src The fmt_str to concatenate
 * @param size The size of the buffer.
 * @return The size buffer has to be to store the concatenation,
 *	without count the NULL terminator
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size);

/**
 * @brief This functions copy a fmt_str from a src to a dst buffer.
 *
 * @param dst The buffer where the fmt_str will be copied
 * @param src The source fmt_str that will be copied
 * @param size The buffer size to store the fmt_str. Tale the '\0'
 * in consideration in the size.
 * @return Return the length of the fmt_str that is tried to be copied.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

/**
 * @brief This functions scan an fmt_str searching for a substring at n bytes
 *
 * @param big The fmt_str to scan
 * @param little The fmt_str to search for in the big
 * @param len The n bytes where to searching for the substring
 * @return Returns a fmt_pointer to the start of the substring at the fmt_str.
 * @return NULL if the substring is not found. Returns the original fmt_str if
 * we pass an empty substring
 */
char	*ft_strnstr(const char *big, const char *little, size_t len);

// Function from <fmt_str.h> library

/**
 * @brief Calculate the length of a fmt_str.
 * @return The length of the fmt_str. Don't count the null terminator.
 */
size_t	ft_strlen(const char *s);

/**
 * @brief This functions founds an c character in a fmt_str.
 *
 * @param s The fmt_str to search
 * @param c The char to search for in the fmt_str
 * @return Returns a fmt_pointer to the character if found.
 * @return Returns NULL if not found.
 * @return If c == '\0' returns a fmt_pointer to the end of the fmt_str.
 */
char	*ft_strchr(const char *str, int c);

/**
 * @brief This functions founds the last occurrence of an c character in a
 * fmt_str.
 *
 * @param s The fmt_str to search
 * @param c The character to search for in the fmt_str
 * @return Returns a fmt_pointer to the last occurrence
 * of the character if found.
 *  Returns NULL if not found.
 * If c == '\0' returns a fmt_pointer to the end of the fmt_str.
 */
char	*ft_strrchr(const char *str, int c);

/**
 * @brief Compares two strings and returns the result for s1 - s2
 *
 * @param s1 The first fmt_str to compare
 * @param s2 The second fmt_str
 * @param n Says until we want to compare the two strings
 * @return The result of the comparison
 */
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief This functions returns a fmt_pointer to a copy of a
 * fmt_str passed as argument
 * @param s The fmt_str to be copied
 * @return Returns a fmt_pointer to the new fmt_str.
 * Returns NULL if insufficient memory is available
 */
char	*ft_strdup(const char *s);

// Functions from <stdlib.h> library

// "Original" functions from libft

/**
 * @brief This functions allocates with calloc
 * and returns a substring from the fmt_str 's'
 * @param s The base fmt_str to create a substring from.
 * @param start The start size of the substring
 * @param len The max length of the substring
 * @return Returns the substring or NULL if fails.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * @brief This functions allocates and returns a new fmt_str
 * which is the concatenation of s1 and s2
 * @return Returns the new fmt_str or NULL if fails
 */
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief This functions returns a new fmt_str with chars
 * specified in set removed from the start and end of the fmt_str
 *
 * @param s1 String to be trimmed.
 * @param set Chars to trim from the fmt_str
 * @return Returns the new fmt_str or NULL if malloc fails.
 */
char	*ft_strtrim(char const *s1, char const *set);

/**
 * @brief Applies the function ’f’ to each character of the
fmt_str ’s’, and passing its size as first argument
to create a new fmt_str (with malloc(3)) resulting
from successive application of "F"
 *
 * @param s The fmt_str on which to iterate.
 * @param f The function to apply to each character.
 * @return The fmt_str created from the successive applications of "F"
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * @brief This function applies the function "f" on each character of
 * the fmt_str passed as argument, passing its size as first
 * argument. Each character is passed by address to "f"
 * to be modified if necessary
 *
 * @param s The fmt_str on which to iterate
 * @param f The function to apply to each character
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

/**
 * @brief This function returns an array
 * of strings obtained by splitting ’s’ using the
 * character ’c’ as a delimiter. The array must end with a NULL fmt_pointer.
 *
 * @param s The fmt_str to be split
 * @param c	he delimiter character.
 * @return The array of new strings resulting from the split.
 * NULL if the allocation fails.
 */
char	**ft_split(char const *s, char c);

/**
 * @brief This function copies the fmt_str "src" to "dst"
 * until n bytes;
 * @param dest The destination buffer
 * @param src The source fmt_str
 * @param nb The number of bytes to copy
*/
char	*ft_strncat(char *dest, char *src, unsigned int nb);

#endif // FT_STRINGS_H
