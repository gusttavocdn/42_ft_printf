#include "libft.h"

int ft_putstr_fd(char *s, int fd)
{
	int str_len;

	if (!s)
		return (0);

	str_len = 0;
	while (s[str_len] != '\0')
	{
		write(fd, &s[str_len], 1);
		str_len++;
	}

	return str_len;
}