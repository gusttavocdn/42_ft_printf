#include "libft.h"

static void show_min_int(char *nbr, int fd);

int ft_putnbr_fd(int n, int fd)
{
	int size;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if (n == -2147483648)
		{
			show_min_int("2147483648", fd);
			return (11);
		}
		n *= -1;
	}
	size = 0;
	if (n < 10)
	{
		size += ft_putchar_fd(n + '0', fd);
		return (size);
	} else
	{
		size += ft_putnbr_fd(n / 10, fd);
		size += ft_putnbr_fd(n % 10, fd);
	}

	return (size);
}

static void show_min_int(char *nbr, int fd)
{
	while (*nbr)
		ft_putchar_fd(*nbr++, fd);
}