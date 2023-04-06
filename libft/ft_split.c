#include "libft.h"

static int count_words(const char *s, char c);

static char *create_word(const char *s, char c);

char **ft_split(char const *s, char c)
{
	size_t words;
	size_t i;
	char **str_arr;

	words = count_words(s, c);
	str_arr = (char **) ft_calloc(words + 1, sizeof(char *));
	if (str_arr == NULL)
		return (NULL);
	i = 0;
	while (i < words)
	{
		if (i > 0)
		{
			while (*s == c)
				s++;
			while (*s != c)
				s++;
			s++;
		}
		str_arr[i] = create_word(s, c);
		i++;
	}
	return (str_arr);
}

static int count_words(const char *s, char c)
{
	size_t words;
	size_t new_word;

	words = 0;
	new_word = 0;
	while (*s)
	{
		if (*s != c && !new_word)
		{
			new_word = 1;
			words++;
		} else if (*s == c)
			new_word = 0;
		s++;
	}
	return (words);
}

static char *create_word(const char *s, char c)
{
	size_t word_len;
	size_t i;
	char *new_str;

	i = 0;
	word_len = 0;
	if (*s == c)
		while (*s == c)
			s++;
	while (s[i] != c && s[i] != '\0')
	{
		word_len++;
		i++;
	}
	new_str = (char *) ft_calloc(word_len + 1, sizeof(char));
	i = 0;
	while (i < word_len)
	{
		new_str[i] = s[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}