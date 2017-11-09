#include "ls.h"

void	ft_openerr(char *arg)
{
	//gerer les differents message d'erreur car la tu fais pas les EACCESS
		ft_putstr_fd(OPENERR, 2);
		ft_putstr_fd(arg, 2);
		perror("'");
}
