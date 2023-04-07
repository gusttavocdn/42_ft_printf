#include "../include/ft_printf.h"

int ft_put_unsigned_fd(int n, int fd)
{
	int size;
	unsigned int nbr;

	size = 0;
	nbr = (unsigned int) n;
	if (nbr < 10)
	{
		size += ft_putchar_fd(nbr + '0', fd);
		return (size);
	} else
	{
		size += ft_put_unsigned_fd(nbr / 10, fd);
		size += ft_put_unsigned_fd(nbr % 10, fd);
	}
	return (size);
}

