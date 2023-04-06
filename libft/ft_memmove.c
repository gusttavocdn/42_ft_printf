#include "libft.h"

void *ft_memmove(void *dest, void *src, size_t n)
{
	char *s;
	char *d;

	if (!dest && !src)
		return (NULL);
	d = (char *) dest;
	s = (char *) src;
	if (d < s)
	{
		while (n--)
			*d++ = *s++;
		return (dest);
	}
	while (n--)
		*(d + n) = *(s + n);
	return (dest);
}
