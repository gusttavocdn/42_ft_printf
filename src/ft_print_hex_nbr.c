#include "../include/ft_printf.h"

int ft_print_hex_nbr(unsigned int number, char type)
{
	int i;
	char str_buffer[33];
	char hex_base[17] = "0123456789abcdef";

	i = 0;
	while (number > 0)
	{
		str_buffer[i] = (char) (hex_base[number % 16]);
		if (type == 'X' && ft_isalpha(str_buffer[i]))
			str_buffer[i] = (char) ft_toupper(str_buffer[i]);
		number /= 16;
		i++;
	}
	str_buffer[i--] = '\0';
	while (i >= 0)
		ft_putchar_fd(str_buffer[i--], STDOUT_FILENO);
	return ((int) ft_strlen(str_buffer));
}