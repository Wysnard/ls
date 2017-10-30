#include "ls.h"

int	ft_total(t_list	*list)
{
	t_list	*tmp;
	info	*inf;
	unsigned int	total;
	int	max;

	tmp = list;
	total = 0;
	max = 0;
	while (tmp)
	{
		inf = (info *)tmp->content;
		if (max < ft_intlen(inf->st->st_size, 10))
			max = ft_intlen(inf->st->st_size, 10);
		total += inf->st->st_blocks;
		tmp = tmp->next;
	}
	ft_printf("total %d\n", total);
	return (max);
}
