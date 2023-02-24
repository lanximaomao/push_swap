# include "push_swap.h"

t_list** create_stack(int *num, int count)
{
	int i;
	t_list *a;

	i = 0;

	a = ft_lstnew((void*)num[i]);
	if (!a)
		exit(1);
	i++;

	while (i < count)
	{
		ft_lstadd_back(&a, ft_lstnew((void*)num[i]));
		i++;
	}
	return(&a);
}

void ft_print_list(t_list **head)
{
	t_list *temp;

	temp = *head;
	while (temp->next)
	{
		ft_printf("%d\n", temp->content);
		temp = temp->next;
	}
}
