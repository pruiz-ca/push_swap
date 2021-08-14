/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 20:50:49 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/07/30 21:50:09 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_insert5numbers(t_ps *ps)
{
	if (ft_ismax(ps, ps->stack_B->num))
	{
		ft_sortstackA(ps);
		ft_push(ps, 1, 1);
		ft_rotate(ps, 0, 1);
	}
	else if (ft_ismin(ps, ps->stack_B->num, 0))
	{
		ft_sortstackA(ps);
		ft_push(ps, 1, 1);
	}
	else
	{
		ft_rotatestackA(ps, ft_getinsertpos(ps));
		ft_push(ps, 1, 1);
	}
}

void	ft_sort5numbers(t_ps *ps)
{
	if (ps->items_A == 5)
		ft_push(ps, 0, 1);
	ft_push(ps, 0, 1);
	ft_sort3numbers(ps);
	if (ps->items_B == 2)
		ft_insert5numbers(ps);
	ft_insert5numbers(ps);
	ft_sortstackA(ps);
}

void	ft_sort3numbers(t_ps *ps)
{
	char	FLAG;

	FLAG = 0;
	if (ps->items_A == 2 && ps->stack_A->num < ps->stack_A->next->num)
		return ;
	if (ps->stack_A->num > ps->stack_A->next->num)
		FLAG |= 4;
	if (ps->stack_A->next->num > ps->stack_A->next->next->num)
		FLAG |= 2;
	if (ps->stack_A->next->next->num > ps->stack_A->num)
		FLAG |= 1;
	if (FLAG == 0b00000101 || FLAG == 0b00000110 || FLAG == 0b00000011)
		ft_swap(ps, 0, 1);
	if (FLAG == 0b00000010 || FLAG == 0b00000110)
		ft_revrotate(ps, 0, 1);
	if (FLAG == 0b00000100 || FLAG == 0b00000011)
		ft_rotate(ps, 0, 1);
}

void	ft_sorthub(t_ps *ps)
{
	if (ft_issorted(ps))
		return ;
	if (ps->items_A <= 3)
		ft_sort3numbers(ps);
	else if (ps->items_A > 3 && ps->items_A <= 5)
		ft_sort5numbers(ps);
	else
		ft_sortbig(ps);
}
