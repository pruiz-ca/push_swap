/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 22:06:54 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/07/31 13:44:10 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swaplistnodes(t_stack *first, t_stack *second)
{
	t_stack		*third;
	t_stack		*last;

	third = second->next;
	last = first->prev;
	last->next = second;
	third->prev = first;
	first->next = second->next;
	second->prev = first->prev;
	second->next = first;
	first->prev = second;
}

void	ft_insertnode(t_stack **src, t_stack **dst)
{
	t_stack		*new;

	new = *src;
	if ((*src)->next != *src)
	{
		(*src)->prev->next = (*src)->next;
		(*src)->next->prev = (*src)->prev;
		(*src) = (*src)->next;
	}
	else
		(*src) = NULL;
	ft_numaddfront(dst, new);
}

/*
** Adds a node to the circular doubly linked list in the last position.
*/
void	ft_numaddback(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	tmp = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		(*lst)->next = new;
		(*lst)->prev = new;
	}
	else
	{
		while (tmp->next && tmp->next != *lst)
			tmp = tmp->next;
		if (tmp)
		{
			new->prev = tmp;
			(*lst)->prev = new;
			tmp->next = new;
			new->next = *lst;
		}
	}
}

/*
** Adds a node to the circular doubly linked list in the first position.
*/
void	ft_numaddfront(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	tmp = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		(*lst)->next = new;
		(*lst)->prev = new;
	}
	else
	{
		new->next = tmp;
		new->prev = tmp->prev;
		tmp->prev->next = new;
		tmp->prev = new;
		*lst = new;
	}
}

void	ft_freelist(t_ps *ps)
{
	t_stack		*tmp;
	int			i;

	i = -1;
	while (++i < ps->items_A)
	{
		tmp = ps->stack_A;
		ps->stack_A = ps->stack_A->next;
		free(tmp);
	}
	i = -1;
	if (++i < ps->items_B)
	{
		tmp = ps->stack_B;
		ps->stack_B = ps->stack_B->next;
		free(tmp);
	}
}
