#include "ls.h"

int	main(int argc, char **argv)
{
	int	i;
	char	flag[6];
	t_list	*wait;

	i = 1;
	wait = NULL;
	flag[0] = '\0';
	ft_get_flag(argc, argv, flag);
	ft_ls(flag, ".");
	return (0);
}
