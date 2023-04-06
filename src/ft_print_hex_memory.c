#include "../include/ft_printf.h"

int ft_print_hex_memory(void *pointer)
{
	const char hex_base[17] = "0123456789abcdef";
	unsigned long adress;
	char str_mem[17];
	int size;
	int i;

	i = 0;
	size = 0;
	adress = (unsigned long) pointer;
	while (adress > 0)
	{
		str_mem[i++] = hex_base[adress % 16];
		adress /= 16;
	}
	str_mem[i] = '\0';
	size += ft_putstr_fd("0x", STDOUT_FILENO);
	while (i-- > 0)
		size += ft_putchar_fd(str_mem[i], STDOUT_FILENO);
	return (size);
}

