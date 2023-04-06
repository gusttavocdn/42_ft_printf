#include "libft.h"

int ft_memcmp(const void *str1, const void *str2, size_t n)
{
	char *s1;
	char *s2;

	if (n == 0)
		return (0);
	s1 = (char *) str1;
	s2 = (char *) str2;
	while (n)
	{
		if ((unsigned char) *s1 != (unsigned char) *s2)
			return ((unsigned char) *s1 - (unsigned char) *s2);
		s1++;
		s2++;
		n--;
	}
	return (0);
}
