#include "libft.h"

void *ft_calloc(size_t nmemb, size_t size)
{
	void *pointer;

	if (nmemb >= 18446744073709551615UL || size >= 18446744073709551615UL
		|| nmemb * size >= 18446744073709551615UL)
		return (NULL);
	pointer = malloc(nmemb * size);
	if (pointer == NULL)
		return (NULL);
	ft_bzero(pointer, nmemb * size);
	return (pointer);
}
