#include "libft.h"

char *ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t l_size;

	if (!big && len == 0)
		return (NULL);
	i = 0;
	l_size = ft_strlen(little);
	if (!l_size)
		return ((char *) big);
	while (big[i] && (i + l_size <= len) && (len != 0))
	{
		if (big[i] == little[0])
		{
			if (!ft_strncmp(&big[i], little, l_size))
				return ((char *) &big[i]);
		}
		i++;
	}
	return (NULL);
}
