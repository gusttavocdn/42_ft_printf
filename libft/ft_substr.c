#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t i;
	size_t s_len;
	size_t substr_len;
	char *substr;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	substr_len = s_len - (size_t) start;
	if (start > s_len)
		return ((char *) ft_calloc(1, sizeof(char)));
	if (substr_len > len)
		substr = (char *) ft_calloc((len + 1), sizeof(char));
	else
		substr = (char *) ft_calloc((substr_len + 1), sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (s[start] && len--)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}
