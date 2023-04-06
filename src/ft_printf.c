#include "../include/ft_printf.h"

static int ft_format_arguments(char type, va_list args_list)
{
	switch (type)
	{
		case 'c':
			return ft_putchar_fd(va_arg(args_list, int), STDOUT_FILENO);
		case 's':
			return ft_putstr_fd(va_arg(args_list, char *), STDOUT_FILENO);
		case 'p':
			return ft_print_hex_memory(va_arg(args_list, void*));
		case 'd':
			return ft_putnbr_fd(va_arg(args_list, int), STDOUT_FILENO);
		case 'u':
			return ft_put_unsigned_fd(va_arg(args_list, unsigned int), STDOUT_FILENO);
		case 'x':
			return ft_print_hex_nbr(va_arg(args_list, unsigned int), 'x');
		case 'X':
			return ft_print_hex_nbr(va_arg(args_list, unsigned int), 'X');
		case '%':
			return ft_putchar_fd('%', STDOUT_FILENO);
		case 'i':
			return ft_putnbr_fd(va_arg(args_list, int), STDOUT_FILENO);
		default:
			return (0);
	}
}

int ft_printf(const char *format, ...)
{
	va_list arguments;
	int output_len;
	int i;

	va_start(arguments, format);
	i = 0;
	output_len = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			output_len += ft_format_arguments(format[++i], arguments);
		else
			output_len += ft_putchar_fd(format[i], STDOUT_FILENO);
		i++;
	}
	va_end(arguments);
	return output_len;
}
