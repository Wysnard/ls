#include "ls.h"

struct	dirent	*direntcpy(struct dirent *dir)
{
	struct	dirent	*cpy;

	if (!(cpy = malloc(sizeof(*cpy))))
		exit (EXIT_FAILURE);
	cpy->d_ino = dir->d_ino;
	cpy->d_off = dir->d_off;
	cpy->d_reclen = dir->d_reclen;
	cpy->d_type = dir->d_type;
	ft_strcpy(cpy->d_name ,dir->d_name);
	return (cpy);
}

info	*createinfo(struct dirent *dir)
{
	info	*elem;

	if (!(elem = malloc(sizeof(*elem))))
		exit(EXIT_FAILURE);
	elem->dir = dir;
	elem->st = NULL;
	return (elem);
}
