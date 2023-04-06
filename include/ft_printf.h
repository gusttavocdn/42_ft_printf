#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include "../libft/libft.h"

/**
 * @brief ft_printf is a recoded version of printf function from stdio.
 * It acts just like the original unless for the fact that it does not do the buffer management like
 * real printf
 * @param format the format string
 * @param ... the arguments
 * @return the number of characters printed
 */
int ft_printf(const char *format, ...);

int ft_print_hex_memory(void *pointer);

int ft_put_unsigned_fd(int n, int fd);

#endif //FT_PRINTF_H
