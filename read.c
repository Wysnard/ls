#include "ls.h"

struct	stat	*ft_getst(struct dirent *entry)
{
	struct	stat	*buf;

	if (entry->d_type == 10)
		lstat(entry->d_name, buf);
	else
		stat(entry->d_name, buf);
	return (statcpy(buf));
}

int	ft_ls(char *flag, char *arg)
{
	DIR		*dir;
	struct	dirent	*entry;
	t_list		*list;
	t_list		*tmp;
	char		*join;

	list = NULL;
	dir = opendir(arg);
	while (entry = readdir(dir))
	{
		if (entry->d_name[0] != '.' || ft_strchr(flag, 'a'))
				ft_lstpushadd(&list ,ft_lstnew(direntcpy(entry), sizeof(*entry)));
	}
	if (ft_strchr(flag, 'R'))
		ft_printf("%s:\n", arg);
	if (ft_strchr(flag, 'r'))
		ft_lstrev(&list);
	ft_printlst(list, flag);
	tmp = list;
	if (ft_strchr(flag, 'R'))
		while (tmp)
		{
			inf = (info *)tmp->content;
			if (dir->d_type == 4 && !ft_strequ(dir->d_name, ".") && !ft_strequ(dir->d_name, ".."))
			{
				ft_putchar('\n');
				join = ft_strtrijoin(arg, "/", dir->d_name);
				ft_ls(flag, join);
				free(join);
			}
			tmp = tmp->next;
		}
	if (list)
		ft_alstdel(list);
	return (1);
}
