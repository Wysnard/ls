#include "ls.h"
#include <stdio.h>

void	ft_filetype(struct dirent *dir)
{
	char	reg[13];

	ft_strcpy(reg, "dddd-----l--");
	ft_printf("%c", reg[dir->d_type - 1]);
}

void	ft_mod(struct stat *buf)
{
	char		str[10];

	ft_strmod(buf->st_mode, str);
	ft_printf("%s %d ", str, buf->st_nlink);
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
	struct	dirent	*entry;

	if (!ft_strchr(flag, 'l'))
		while (list)
		{
			inf = (info *)list->content;
			ft_printf("%s\n", inf->dir->d_name);
			list = list->next;
		}
	else
	{
		/*if (list)
			ft_total(list);*/
		while (list)
		{
			inf = (info *)list->content;
			ft_filetype(inf->dir);
			ft_printf("%d ", inf->st->st_size);
			ft_mod(inf->st);
			ft_uid(inf->st);
			ft_gid(inf->st);
			ft_printf("%s\n", inf->dir->d_name);
			list = list->next;
		}
	}
}
