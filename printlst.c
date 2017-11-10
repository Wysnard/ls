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

static	void	ft_printfcontent(struct dirent *entry, char *arg)
{
	char	buf[256];
	int	ret;
	char	*join;

	ft_printf("%s", entry->d_name);
	if (entry->d_type == DT_LNK)
	{
		ret = readlink(ft_strjoin(ft_strjoin(arg, "/"), entry->d_name), buf, 255);
		buf[ret] = '\0';
		ft_printf(" -> %s", buf);
	}
	ft_putchar('\n');
}

void ft_printl(struct dirent *entry, int max, char *arg)
{
	struct	stat	buf;

	//Faire les majeurs et mineurs de /dev
	ft_filetype(entry);
	if (entry->d_type == DT_LNK || entry->d_type == DT_UNKNOWN)
		lstat(ft_strjoin(ft_strjoin(arg, "/"), entry->d_name), &buf);
	else
		stat(ft_strjoin(ft_strjoin(arg, "/"), entry->d_name), &buf);
	ft_mod(&buf);
	ft_uid(&buf);
	ft_gid(&buf);
	ft_printsize(max, &buf);
	//gerer les date de plus de 6mois
	ft_printf("%.12s ", &ctime(&buf.st_mtime)[4]);
	ft_printfcontent(entry, arg);
}

/*void	ft_printlst(t_list *list, char *flag, char *arg)
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
			ft_printl(list, max, arg);
			list = list->next;
		}
	}
}*/

void	ft_btrprt(void *content)
{
	info	*inf;

	inf = (info *)content;
	ft_printf("%s\n", inf->dir->d_name);
}

void	ft_prtlst(t_list *elem)
{
	char	*str;

	str = (char *)elem->content;
	ft_printf("%s\n", str);
}
