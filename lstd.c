#include "ls.h"

void	ft_lstdellast(t_list *list)
{
	t_list	*tmp;
	t_list	*before;

	if (!(tmp = list))
		return ;
	if (!tmp->next)
		free (tmp);
	else
	{
		while (tmp->next)
		{
			before = tmp;
			tmp = tmp->next;
		}
		before->next = NULL;
		free (tmp);
	}
}

void	ft_alstdel(t_list *list)
{
	while (list)
		ft_lstdellast(list);
}
