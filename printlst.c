#include "ls.h"
#include <stdio.h>

void	ft_filetype(struct dirent *dir)
{
	if (dir->d_type == DT_REG)
		ft_putchar('-');
	else if (dir->d_type == DT_BLK)
		ft_putchar('b');
	else if (dir->d_type == DT_CHR)
		ft_putchar('c');
	else if (dir->d_type == DT_DIR)
		ft_putchar('d');
	else if (dir->d_type == DT_FIFO)
		ft_putchar('p');
	else if (dir->d_type == DT_LNK)
		ft_putchar('l');
	else if (dir->d_type == DT_SOCK)
		ft_putchar('s');
}

void	ft_printfcontent(info *inf, char *arg)
{
	char	buf[256];
	int	ret;
	char	*join;

	ft_printf("%s", inf->dir->d_name);
	if (inf->dir->d_type == DT_LNK)
	{
		ret = readlink(join = ft_strtrijoin(arg, "/", f->dir->d_name), buf, 255);
		buf[ret] = '\0';
		ft_printf(" -> %s", buf);
		free (join);
	}
	ft_putchar('\n');
}

void ft_printl(t_list *list, int max)
{
	info	*inf;

	inf = (info *)list->content;
	ft_filetype(inf->dir);
	ft_mod(inf->st);
	ft_uid(inf->st);
	ft_gid(inf->st);
	ft_printsize(max, inf->st);
	ft_printf("%.12s ", &ctime(&inf->st->st_mtime)[4]);
	ft_printfcontent(inf, arg);
}

void	ft_printlst(t_list *list, char *flag, char *arg)
{
	info		*inf;
	struct	dirent	*entry;
	int		max;

	if (!ft_strchr(flag, 'l'))
		while (list)
		{
			inf = (info *)list->content;
			ft_printf("%s\n", inf->dir->d_name);
			list = list->next;
		}
	else
	{
		if (list)
			max = ft_total(list);
		while (list)
		{
			ft_printl(list, max);
			list = list->next;
		}
	}
}
