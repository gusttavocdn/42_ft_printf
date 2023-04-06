#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *head;

	if (!lst || !del)
		return;

	while (*lst != NULL)
	{
		head = *lst;
		*lst = (*lst)->next;
		del(head->content);
		free(head);
	}
}