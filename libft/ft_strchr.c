#include "libft.h"

char *ft_strchr(const char *str, int c)
{
	char *s;

	s = (char *) str;
	while (*s)
	{
		if (*s == (char) c)
			return (s);
		s++;
	}
	if (!c && !(*s))
		return (s);
	return (NULL);
}