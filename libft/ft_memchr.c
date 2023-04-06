#include "libft.h"

void *ft_memchr(const void *str, int c, size_t n)
{
	unsigned char *p;

	p = (void *) str;
	while (n)
	{
		if (*p == (unsigned char) c)
			return (p);
		p++;
		n--;
	}
	return (NULL);
}