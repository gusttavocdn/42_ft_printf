/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusda-si <gusda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 20:22:13 by gusda-si          #+#    #+#             */
/*   Updated: 2023/07/25 18:38:59 by gusda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static char		*create_word(const char *s, char c);
static size_t	count_words(const char *s, char c);
static size_t	walk_through_delimiters(const char *s, char c);
static void		*free_str_arr_on_error(char **str_arr, size_t size);

char	**ft_split(char const *s, char c)
{
	size_t	current_word;
	char	**str_arr;
	size_t	words_qnt;

	words_qnt = count_words(s, c);
	str_arr = (char **)ft_calloc(words_qnt + 1, sizeof(char *));
	if (!str_arr)
		return (NULL);
	if (words_qnt == 0)
		return (str_arr);
	current_word = 0;
	while (current_word < words_qnt)
	{
		s += walk_through_delimiters(s, c);
		str_arr[current_word] = create_word(s, c);
		if (!str_arr[current_word])
			return (free_str_arr_on_error(str_arr, current_word));
		s += ft_strlen(str_arr[current_word]);
		current_word++;
	}
	return (str_arr);
}

static void	*free_str_arr_on_error(char **str_arr, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(str_arr[i]);
		i++;
	}
	free(str_arr);
	return (NULL);
}

static size_t	count_words(const char *s, char c)
{
	size_t	counter;
	int		is_new_word;

	counter = 0;
	is_new_word = FALSE;
	while (*s != '\0')
	{
		if (*s != (unsigned char)c && !is_new_word)
		{
			is_new_word = TRUE;
			counter++;
		}
		if (*s == (unsigned char)c)
			is_new_word = FALSE;
		s++;
	}
	return (counter);
}

static char	*create_word(const char *s, char c)
{
	char	*new_str;
	size_t	str_len;
	size_t	i;

	str_len = 0;
	while (*s == c)
		s++;
	while (s[str_len] != '\0' && s[str_len] != (unsigned char)c)
		str_len++;
	new_str = (char *)ft_calloc(str_len + NULL_BYTE, sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < str_len)
	{
		new_str[i] = s[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

static size_t	walk_through_delimiters(const char *s, char c)
{
	size_t	walked_bytes;

	if (!s)
		return (0);
	walked_bytes = 0;
	while (*s == (unsigned char)c)
	{
		walked_bytes++;
		s++;
	}
	return (walked_bytes);
}
