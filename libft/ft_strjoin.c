#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
	size_t str_len;
	char *str;
	size_t i;
	size_t j;

	if (!s1 || !s2)
		return (NULL);
	str_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc((str_len) * sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = -1;
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = '\0';
	return (str);
}
