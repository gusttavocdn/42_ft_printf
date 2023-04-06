#include "libft.h"

char *ft_strrchr(const char *str, int c)
{
	char *s;
	size_t size;

	s = (char *) str + (ft_strlen(str));
	if (!c)
		return (s);
	size = ft_strlen(str) + 1;
	while (0 < size)
	{
		if ((unsigned char) *s == (unsigned char) c)
			return (s);
		size--;
		s--;
	}
	return (NULL);
}
