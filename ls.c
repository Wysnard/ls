#include "ls.h"

struct	stat	*ft_getst(struct dirent *dir, char *arg)
{
	struct	stat	*buf;

	if (!(buf = (struct stat *)malloc(sizeof(struct stat))))
		exit(EXIT_FAILURE);
	if (dir->d_type == DT_LNK || dir->d_type == DT_UNKNOWN)
		lstat(ft_strjoin(ft_strjoin(arg, "/"), dir->d_name), buf);
	else
		stat(ft_strjoin(ft_strjoin(arg, "/"), dir->d_name), buf);
	return (buf);
}

int	ft_ls(char *flag, char *arg)
{
	DIR			*dir;
	struct	dirent	*entry;
	t_list			*list;
	int			max;

	list = NULL;
	if (ft_strchr(flag, 'l'))
		if ((max = ft_total(arg)) < 0)
			return (-1);
	if (!(dir = opendir(arg)))
	{
		ft_openerr(arg);
		return (-1);
	}
	while (entry = readdir(dir))
		if (entry->d_name[0] != '.' || ft_strchr(flag, 'a'))
		{
			if (!ft_strchr(flag, 't') || !ft_strchr(flag, 'r'))
			{
				if (ft_strchr(flag, 'R') && entry->d_type == DT_DIR)
					ft_lstpushadd(&list ,ft_lstnew(ft_strdup(entry->d_name), sizeof(char *)));
				if (ft_strchr(flag, 'l'))
					ft_printl(entry, max, arg);
				else
					ft_printf("%s\n", entry->d_name);
			}
		}
	/*ft_options(flag, arg, &list);
	ft_printlst(list, flag, arg);
	if (ft_strchr(flag, 'R'))
		ft_recurss(list, arg, flag);*/
	return (1);
}
