#include "ls.h"

struct	stat	*ft_getst(struct dirent *dir, char *arg)
{
	struct	stat	*buf;

	if (!(buf = (struct stat *)malloc(sizeof(struct stat))))
		exit(EXIT_FAILURE);
	if (dir->d_type == DT_LNK || dir->d_type == DT_UNKNOWN)
		lstat(ft_strtrijoin(arg, "/", dir->d_name), buf);
	else
		stat(ft_strtrijoin(arg, "/", dir->d_name), buf);
	return (buf);
}

int	ft_ls(char *flag, char *arg)
{
	DIR		*dir;
	struct	dirent	*entry;
	t_list		*list;

	list = NULL;
	if (!(dir = opendir(arg)))
	{
	//gerer les differents message d'erreur car la tu fais pas les EACCESS
		write(2, OPENERR, ft_strlen(OPENERR));
		write(2, arg, ft_strlen(arg));
		perror("'");
		return (-1);
	}
	if (ft_strchr(flag, 'r') || ft_strchr(flag, 'l') || ft_strchr(flag, 't'))
		while (entry = readdir(dir))
			if (entry->d_name[0] != '.' || ft_strchr(flag, 'a'))
				ft_lstpushadd(&list ,ft_lstnew(createinfo(direntcpy(entry), ft_getst(entry, arg)), sizeof(info *)));
	else
		while (entry = readdir(dir))
			ft_printf("%s\n", entry->d_name);
	ft_options(flag, arg, &list);
	if (ft_strchr(flag, 'r') || ft_strchr(flag, 'l') || ft_strchr(flag, 't'))
		ft_printlst(list, flag, arg);
	if (ft_strchr(flag, 'R'))
		ft_recurss(list, arg, flag);
	return (1);
}
