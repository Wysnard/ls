#include "ls.h"

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
			ft_lstpushadd(&list ,ft_lstnew(createinfo(direntcpy(entry)), sizeof(*entry)));
	}
	/*if (ft_strchr(flag, 'R'))
		ft_printf("%s:\n", arg);
	if (ft_strchr(flag, 'r'))
		ft_lstrev(&list);
	ft_printlst(list, flag);
	tmp = list;
	if (ft_strchr(flag, 'R'))
		while (tmp)
		{
			entry = (struct dirent *)tmp->content;
			if (entry->d_type == 4 && !ft_strequ(entry->d_name, ".") && !ft_strequ(entry->d_name, ".."))
			{
				ft_putchar('\n');
				join = ft_strjoin(arg, "/");
				join = ft_strjoin(join, entry->d_name);
				ft_ls(flag, join);
				free(join);
			}
			tmp = tmp->next;
		}*/
	if (list)
		ft_alstdel(list);
	return (1);
}
