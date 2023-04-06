#include "libft.h"

size_t ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t f_len;

	if (!dst && size == 0)
		return (ft_strlen(src) + size);

	f_len = ft_strlen(dst) + ft_strlen(src);
	i = ft_strlen(dst);
	j = 0;

	if (size > i)
	{
		while (src[j] && i < size - 1)
			dst[i++] = src[j++];
		dst[i] = '\0';
		return (f_len);
	}
	return (ft_strlen(src) + size);
}