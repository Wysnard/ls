#include "ls.h"

static t_list	*ft_lstmerge(t_list *a, t_list *b)
{
	t_list	*result;
	info	*ai;
	info	*bi;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	ai = (info *)a->content;
	bi = (info *)b->content;
	if (ai->st->st_mtime > bi->st->st_mtime)
	{
		result = a;
		result->next = ft_lstmerge(a->next, b);
	}
	else
	{
		result = b;
		result->next = ft_lstmerge(a, b->next);
	}
	return (result);
}

void	ft_lstmergesort(t_list **list)
{
	t_list	*head;
	t_list	*a;
	t_list	*b;

	head = *list;
	if (head == NULL || head->next == NULL)
		return ;
	ft_lstfrontbacksplit(head, &a, &b);

	ft_lstmergesort(&a);
	ft_lstmergesort(&b);

	*list = ft_lstmerge(a, b);
}

int	ft_compare(void *s1, void *s2)
{
	info	*inf1;
	info	*inf2;

	inf1 = (info *)s1;
	inf2 = (info *)s2;
	return (inf2->st->st_mtime - inf1->st->st_mtime);
}
