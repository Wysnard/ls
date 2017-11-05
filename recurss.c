#include "ls.h"

void	ft_recurss(t_list *list)
{
	t_list		*tmp;
	info		*inf;
	char		*join;
	
	tmp = list;
	if (ft_strchr(flag, 'R'))
		while (tmp)
		{
			inf = (info *)tmp->content;
			if (inf->dir->d_type == 4 && !ft_strequ(inf->dir->d_name, ".") && !ft_strequ(inf->dir->d_name, ".."))
			{
				ft_putchar('\n');
				join = ft_strtrijoin(arg, "/", inf->dir->d_name);
				ft_ls(flag, join);
				free(join);
			}
			tmp = tmp->next;
		}
}
