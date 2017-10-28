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

struct	stat	*statcpy(struct stat *cp)
{
	struct	stat	*st;

	if (!(st = malloc(sizeof(*st))))
		exit (EXIT_FAILURE);
	st->st_dev = cp->st_dev;
	st->st_ino = cp->st_ino;
	st->st_mode = cp->st_mode;
	st->st_nlink = cp->st_nlink;
	st->st_uid = cp->st_uid;
	st->st_gid = cp->st_gid;
	st->st_rdev = cp->st_rdev;
	st->st_size = cp->st_size;
	st->st_blksize = cp->st_blksize;
	st->st_blocks = cp->st_blocks;
	st->st_atime = cp->st_atime;
	st->st_mtime = cp->st_mtime;
	st->st_ctime = cp->st_ctime;
	return (st);
}

info	*createinfo(struct dirent *dir, struct stat st)
{
	info	*elem;

	if (!(elem = malloc(sizeof(*elem))))
		exit(EXIT_FAILURE);
	elem->dir = dir;
	elem->st = st;
	return (elem);
}
