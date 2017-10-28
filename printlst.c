#include "ls.h"
#include <stdio.h>

void	ft_filetype(struct dirent *dir)
{
	char	reg[13];

	ft_strcpy(reg, "dddd-----l--");
	ft_printf("%c", reg[dir->d_type - 1]);
}

void	ft_mod(info *inf)
{
	struct	stat	*buf;
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

void	ft_getst(struct dirent *dir)
{
	struct	stat	*buf;

	if (dir->d_type == 10)
		lstat(dir->d_name, buf);
	else
		stat(dir->d_name, buf);
	//ft_mod(inf);
	//ft_uid(buf);
	//ft_gid(buf);
	ft_printf("%d ", buf->st_size);
}

void	ft_printlst(t_list *list, char *flag)
{
	info	*inf;
	struct	dirent	*entry;

	if (!ft_strchr(flag, 'l'))
		while (list)
		{
			entry = (struct dirent *)list->content;
			ft_printf("%s\n", entry->d_name);
			list = list->next;
		}
	else
	{
		/*if (list)
			ft_total(list);*/
		while (list)
		{
			entry = (struct dirent *)list->content;
			ft_filetype(entry);
			//ft_getst(entry);
			ft_printf("%s\n", entry->d_name);
			list = list->next;
		}
	}
}
