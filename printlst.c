#include "ls.h"
#include <stdio.h>

void	ft_filetype(struct dirent *dir)
{
	char	reg[13];

	ft_strcpy(reg, "dddd-----l--");
	ft_printf("%c", reg[dir->d_type - 1]);
}

void	ft_strmod(mode_t mode, char *buf)
{
	char	chars[10];
	int		i;

	i = 0 ;
	ft_strcpy(chars, "rwxrwxrwx");
	while (i < 9)
	{
		buf[i] = (mode & (1 << (8-i))) ? chars[i] : '-';
		i++;
	}
	buf[9] = '\0';
}

void	ft_uid(struct stat *buf)
{
	struct	passwd	*user;

	user = getpwuid(buf->st_uid);
	ft_printf("%s ", user->pw_name);
}

void	ft_gid(struct stat *buf)
{
	struct	group	*grp;

	grp = getgrgid(buf->st_gid);
	ft_printf("%s ", grp->gr_name);
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
	struct	dirent	*dir;

	while (list)
	{
		dir = (struct dirent *)list->content;
		if (ft_strchr(flag, 'l'))
		{
			ft_getl(dir);
			ft_printf("%s\n", dir->d_name);
		}
		else
			ft_printf("%s\n", dir->d_name);
		list = list->next;
	}
}
