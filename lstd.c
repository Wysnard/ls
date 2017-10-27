#include "ls.h"

void	ft_alstdel(t_list *list)
{
	t_list	*tmp;
	t_list	*before;

	tmp = list;
	before = list;
	while (tmp)
	{
		before = tmp;
		tmp = tmp->next;
		free(before);
	}
}
