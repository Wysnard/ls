#include "ls.h"

void	ft_alstdel(t_list *list)
{
	if (list == NULL)
		return ;
	ft_alstdel(list->next);
	free(list);
}
