#include "ls.h"

int	ft_ls(char *flag, char *arg)
{
	DIR			*dir;
	struct	dirent	*entry;
	t_list			*list;
	int			max;
	t_btree		*tr;

	list = NULL;
	tr = NULL;
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
			if (!ft_strchr(flag, 't') && !ft_strchr(flag, 'r'))
			{
				if (ft_strchr(flag, 'R') && entry->d_type == DT_DIR)
					ft_lstpushadd(&list ,ft_lstnew(ft_strdup(entry->d_name), sizeof(char *)));
				if (ft_strchr(flag, 'l'))
					ft_printl(entry, max, arg);
				else
					ft_printf("%s\n", entry->d_name);
			}
			else if (ft_strchr(flag, 't'))
			{
				if (!ft_strchr(flag, 'r'))
					ft_btreeinsert(&tr, createinfo(direntcpy(entry), ft_getst(entry, arg)), &ft_compare);
				else
					ft_btreeinsert(&tr, createinfo(direntcpy(entry), ft_getst(entry, arg)), &ft_revcompare);
			}
			else if (ft_strchr(flag, 'r'))
				ft_lstadd(&list ,ft_lstnew(ft_strdup(entry->d_name), sizeof(char *)));
		}
	if (tr)
	{
		if (ft_strchr(flag, 'r'))
			ft_btree_rev_infix(tr, &ft_btrprt);
		else
			ft_btree_apply_infix(tr, &ft_btrprt);
	}
	/*ft_options(flag, arg, &list);
	ft_printlst(list, flag, arg);
	if (ft_strchr(flag, 'R'))
		ft_recurss(list, arg, flag);*/
	return (1);
}
