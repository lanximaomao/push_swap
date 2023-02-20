/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsun <lsun@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:19:18 by lsun              #+#    #+#             */
/*   Updated: 2023/02/20 17:10:19 by lsun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//sa (swap a): Swap the first 2 elements at the top of stack a.
//Do nothing if there is only one or no elements.
//sb (swap b): Swap the first 2 elements at the top of stack b.
//Do nothing if there is only one or no elements.
//ss : sa and sb at the same time.
//pa (push a): Take the first element at the top of b and put it at the top of a.
//Do nothing if b is empty.
//pb (push b): Take the first element at the top of a and put it at the top of b.
//Do nothing if a is empty.
//ra (rotate a): Shift up all elements of stack a by 1.
//The first element becomes the last one.
//rb (rotate b): Shift up all elements of stack b by 1.
//The first element becomes the last one.
//rr : ra and rb at the same time.
//rra (reverse rotate a): Shift down all elements of stack a by 1.
//The last element becomes the first one.
//rrb (reverse rotate b): Shift down all elements of stack b by 1.
//The last element becomes the first one.
//rrr : rra and rrb at the same time.

# include "push_swap.h"

//create new node

t_stack	*ft_new_node(int num, int pos)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));//free
	if (!new)
		return (NULL);
	new->num = num;
	new->pos = pos;
	new->next = NULL;
	return(new);
}

void ft_add_back(t_stack **head, t_stack *new)
{
	t_stack *temp;

	if (!head)
		return;
	if (!*head)
		*head = new;
	temp = head;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

// how to create a stack a

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;

	if (lst)
	{
		new_lst = ft_lstnew(f(lst->content));
		if (!new_lst)
			return (NULL);
		lst = lst->next;
	}
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}

//

void create_stack(t_ps *ps)
{
	int i;
	int j;


	i = 0;
	j = 0;

	while (i < ps->len)
	{
		ft_lstadd_back(NULL, ft_new_node(ps->int_array[i]));//??
		i++;
		j++;
	}
}

void ft_print_list(t_ps *ps)
{
	while (/* condition */)
	{
		/* code */
	}
}



