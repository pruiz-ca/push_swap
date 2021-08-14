/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 15:01:11 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/07/30 21:50:27 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_ps *ps, int rot, int print)
{
	t_stack		*tmp;
	t_stack		*head;

	if (ps->stack_A && (rot == 0 || rot == 2))
	{
		head = ps->stack_A;
		tmp = head->next;
		ft_swaplistnodes(head, tmp);
		ps->stack_A = tmp;
	}
	if (ps->stack_B && (rot == 1 || rot == 2))
	{
		head = ps->stack_B;
		tmp = head->next;
		ft_swaplistnodes(head, tmp);
		ps->stack_B = tmp;
	}
	if (rot == 0 && print)
		ft_putstr_fd("sa\n", 1);
	if (rot == 1 && print)
		ft_putstr_fd("sb\n", 1);
	if (rot == 2 && print)
		ft_putstr_fd("ss\n", 1);
}

void	ft_push(t_ps *ps, int rot, int print)
{
	if (rot == 0 && ps->stack_A)
	{
		ft_insertnode(&ps->stack_A, &ps->stack_B);
		ps->items_A--;
		ps->items_B++;
	}
	if (rot == 1 && ps->stack_B)
	{
		ft_insertnode(&ps->stack_B, &ps->stack_A);
		ps->items_B--;
		ps->items_A++;
	}
	if (rot == 0 && print)
		ft_putstr_fd("pb\n", 1);
	if (rot == 1 && print)
		ft_putstr_fd("pa\n", 1);
}

/*
** These two functions are the reason why I chose a circular doubly linked
** list. It makes rotations way easier since you just move the reference
** pointer one step up or down.
*/
void	ft_rotate(t_ps *ps, int rot, int print)
{
	if (ps->stack_A && (rot == 0 || rot == 2))
		ps->stack_A = ps->stack_A->next;
	if (ps->stack_B && (rot == 1 || rot == 2))
		ps->stack_B = ps->stack_B->next;
	if (rot == 0 && print)
		ft_putstr_fd("ra\n", 1);
	if (rot == 1 && print)
		ft_putstr_fd("rb\n", 1);
	if (rot == 2 && print)
		ft_putstr_fd("rr\n", 1);
}

void	ft_revrotate(t_ps *ps, int rot, int print)
{
	if (ps->stack_A && (rot == 0 || rot == 2))
		ps->stack_A = ps->stack_A->prev;
	if (ps->stack_B && (rot == 1 || rot == 2))
		ps->stack_B = ps->stack_B->prev;
	if (rot == 0 && print)
		ft_putstr_fd("rra\n", 1);
	if (rot == 1 && print)
		ft_putstr_fd("rrb\n", 1);
	if (rot == 2 && print)
		ft_putstr_fd("rrr\n", 1);
}
