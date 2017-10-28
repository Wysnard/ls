#include "ls.h"
#include <stdio.h>

void	ft_filetype(struct dirent *dir)
{
	char	reg[13];

	ft_strcpy(reg, "dddd-----l--");
	ft_printf("%c", reg[dir->d_type - 1]);
}

void	ft_getst(info *inf)
{
	struct	stat	*buf;

	if (inf->dir->d_type == 10)
		lstat(inf->dir->d_name, buf);
	else
		stat(inf->dir->d_name, buf);
	inf->st = statcpy(buf);
}

void	ft_mod(info *inf)
{
	char		str[10];

	ft_strmod(inf->st->st_mode, str);
	ft_printf("%s %d ", str, inf->st->st_nlink);
}

void	ft_total(t_list	*list)
{
	t_list	*tmp;
	info	*inf;
	unsigned int	total;

	tmp = list;
	total = 0;
	while (tmp)
	{
		inf = (info *)tmp->content;
		total += inf->st->st_blocks;
		tmp = tmp->next;
	}
	ft_printf("total %u\n", total);
}

void	ft_printlst(t_list *list, char *flag)
{
	info	*inf;
	t_list	*tmp;

	tmp = list;
	while (tmp)
	{
		inf = (info *)tmp->content;
		if (ft_strchr(flag, 'l'))
			ft_getst(inf);
		else
			ft_printf("%s\n", inf->dir->d_name);
		tmp = tmp->next;
	}
	if (ft_strchr(flag, 'l'))
	{
		ft_total(list);
		while (list)
		{
			inf = (info *)list->content;
			ft_filetype(inf->dir);
			ft_mod(inf);
			ft_uid(inf->st);
			ft_gid(inf->st);
			ft_printf("%d ", inf->st->st_size);
			ft_printf("%s\n", inf->dir->d_name);
			list = list->next;
		}
	}
}
