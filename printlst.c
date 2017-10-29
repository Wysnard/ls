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

void	ft_printfcontent(info *inf)
{
	char	buf[256];
	int	ret;

	ft_printf("%s", inf->dir->d_name);
	if (inf->dir->d_type == DT_LNK)
	{
		ret = readlink(inf->dir->d_name, buf, 255);
		buf[ret] = '\0';
		ft_printf(" -> %s", buf);
	}
	ft_putchar('\n');
}

void	ft_printlst(t_list *list, char *flag)
{
	info	*inf;
	struct	dirent	*entry;

	if (!ft_strchr(flag, 'l'))
		while (list)
		{
			inf = (info *)list->content;
			ft_printfcontent(inf);
			list = list->next;
		}
	else
	{
		if (list)
			ft_total(list);
		while (list)
		{
			inf = (info *)list->content;
			ft_filetype(inf->dir);
			ft_mod(inf->st);
			ft_uid(inf->st);
			ft_gid(inf->st);
			ft_printf("%d ", inf->st->st_size);
			ft_printf("%.13s ", &ctime(&inf->st->st_mtime)[4]);
			ft_printf("%s\n", inf->dir->d_name);
			list = list->next;
		}
	}
}
