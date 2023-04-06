#include "libft.h"

char *ft_strdup(const char *s)
{
	size_t i;
	char *new_string;

	new_string = (char *) malloc(ft_strlen(s) + sizeof(char));
	if (new_string == NULL)
		return NULL;
	i = 0;
	while (s[i])
	{
		new_string[i] = s[i];
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}
