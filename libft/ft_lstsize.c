#include "libft.h"

int ft_lstsize(t_list *lst)
{
	size_t size;

	if (!lst)
		return (0);

	size = 1;
	while (lst->next != NULL)
	{
		size++;
		lst = lst->next;
	}

	return (size);
}