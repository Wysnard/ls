#include "ls.h"

void	ft_recurss(t_list *list, char *arg, char *flag)
{
	t_list		*tmp;
	info		*inf;

	tmp = list;
	while (tmp)
	{
		inf = (info *)tmp->content;
		if (inf->dir->d_type == 4 && !ft_strequ(inf->dir->d_name, ".") && !ft_strequ(inf->dir->d_name, ".."))
		{
			ft_putchar('\n');
			ft_ls(flag, ft_strjoin(ft_strjoin(arg, "/"), inf->dir->d_name));
		}
		tmp = tmp->next;
	}
}
