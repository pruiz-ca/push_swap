/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 23:33:36 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/07/31 01:49:41 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_convertnums(t_ps *ps)
{
	int		i;
	int		converted;
	t_stack	*tmp;

	i = 0;
	converted = 0;
	tmp = ps->stack_A;
	while (1)
	{
		if (!tmp->relative && ft_ismin(ps, tmp->num, 1))
		{
			tmp->num = i;
			tmp->relative = 1;
			i++;
		}
		tmp = tmp->next;
		if (i == ps->items_A)
			break ;
	}
}

void	ft_createchunks(t_ps *ps)
{
	int		i;
	int		j;
	t_stack	*tmp;

	i = 0;
	j = 1;
	while (ps->items_A != 0)
	{
		tmp = ps->stack_A;
		if (tmp->num < (ps->chunk * j))
		{
			ft_push(ps, 0, PRINTMOVES);
			if (tmp->num < (ps->chunk * j) - (ps->chunk / 2))
				ft_rotate(ps, 1, PRINTMOVES);
			i++;
		}
		else
			ft_rotate(ps, 0, PRINTMOVES);
		if (i == ps->chunk * j)
			j++;
	}
}

void	ft_getnumtotop(t_ps *ps, int num)
{
	t_stack		*tmp;
	int			pos;

	tmp = ps->stack_B;
	pos = 0;
	while (1)
	{
		if (tmp->num == num)
		{
			break ;
		}
		pos++;
		tmp = tmp->next;
	}
	ft_rotatestackB(ps, pos, num);
}

void	ft_sendbackinorder(t_ps *ps)
{
	int		i;

	i = ps->items_B;
	while (--i >= 0)
	{
		ft_getnumtotop(ps, i);
		ft_push(ps, 1, PRINTMOVES);
		if (ps->mustswap == 1)
		{
			if (ps->items_B > 1 && ps->stack_B->num < ps->stack_B->next->num)
				ft_swap(ps, 2, PRINTMOVES);
			else
				ft_swap(ps, 0, PRINTMOVES);
			ps->mustswap = 0;
			i--;
		}
	}
}

void	ft_sortbig(t_ps *ps)
{
	ft_convertnums(ps);
	ft_createchunks(ps);
	ft_sendbackinorder(ps);
}
