#include "libft.h"

static int s_isspace(int c);

static int s_count_decimals(const char *str);

static int s_power(int base, int exponent);

int ft_atoi(const char *s)
{
	int signal;
	int number;
	int decimals;

	while (s_isspace(*s))
		s++;

	signal = 1;
	while (*s == '+' || *s == '-')
	{
		if (*s == '-')
			signal *= -1;
		s++;
	}

	decimals = s_count_decimals(s);
	number = 0;
	while (*s && (*s >= '0' && *s <= '9'))
	{
		number += (*s - '0') * s_power(10, --decimals);
		s++;
	}
	return number * signal;
}

static int s_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f' ||
			c == '\v');
}

static int s_power(int base, int exponent)
{
	int i = 1;
	int result = base;

	if (exponent == 0)
		return 1;

	while (i < exponent)
	{
		result *= base;
		i++;
	}

	return result;
}

static int s_count_decimals(const char *str)
{
	int i = 0;

	while (*str && *str >= '0' && *str <= '9')
	{
		i++;
		str++;
	}

	return i;
}
