#include "ls.h"
#include <stdio.h>

void	ft_filetype(struct dirent *dir)
{
	char	reg[13];

	ft_strcpy(reg, "dddd-----l--");
	ft_printf("%c", reg[dir->d_type - 1]);
}

void	ft_getl(struct dirent *dir)
{
	char		str[10];
	struct	stat	*buf;

	if (dir->d_type == 10)
		lstat(dir->d_name, buf);
	else
		stat(dir->d_name, buf);
	ft_filetype(dir);
	ft_strmod(buf->st_mode, str);
	ft_printf("%s %d ", str, buf->st_nlink);
	ft_uid(buf);
	ft_gid(buf);
	ft_printf("%d ", buf->st_size);
}

void	ft_printlst(t_list *list, char *flag)
{
	info	*inf;

	while (list)
	{
		inf = (info *)list->content;
		/*if (ft_strchr(flag, 'l'))
		{
			ft_getl(dir);
			ft_printf("%s\n", dir->d_name);
		}
		else*/
			ft_printf("%s\n", inf->dir->d_name);
		list = list->next;
	}
}
