#include "ls.h"

int	main(int argc, char **argv)
{
	int	i;
	char	*str;
	char	flag[6];
	t_list	*wait;

	i = 1;
	wait = NULL;
	flag[0] = '\0';
	while (i < argc)
	{
		if (argv[i][0] == '-')
			ft_strcat(flag, &argv[i][1]);
		else
			ft_lstpushadd(&wait, ft_lstnew(ft_strdup(argv[i]), sizeof(argv[i])));	
		i++;
	}
	if (!wait)
		ft_ls(flag, ".");
	while (wait)
	{
		if (!ft_strchr(flag, 'R'))
			ft_printf("%s:\n", wait->content);
		ft_ls(flag, wait->content);
		wait = wait->next;
		if (!ft_strchr(flag, 'R'))
			ft_printf("\n");
	}
	return (0);
}
