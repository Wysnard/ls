#include "ls.h"
#include <stdio.h>

void	ft_filetype(struct dirent *dir)
{
	char	reg[13];

	ft_strcpy(reg, "dddd-----l--");
	ft_printf("%c", reg[dir->d_type - 1]);
}

void	ft_getl(info *inf)
{
	char		str[10];
	struct	stat	*buf;

	if (inf->dir->d_type == 10)
		lstat(inf->dir->d_name, buf);
	else
		stat(inf->dir->d_name, buf);
	inf->st = statcpy(buf);
	ft_filetype(inf->dir);
	ft_strmod(buf->st_mode, str);
	ft_printf("%s %d ", str, buf->st_nlink);
	ft_uid(inf->st);
	ft_gid(inf->st);
	ft_printf("%d ", buf->st_size);
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
		{
			ft_getl(inf);
			//ft_printf("%s\n", inf->dir->d_name);
		}
		else
			ft_printf("%s\n", inf->dir->d_name);
		tmp = tmp->next;
	}
}
