/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 12:22:56 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/07/30 21:50:42 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ismin(t_ps *ps, int num, int convert)
{
	int		i;
	t_stack	*tmp;

	i = -1;
	tmp = ps->stack_A;
	while (++i < ps->items_A)
	{
		if (convert && tmp->num < num && !tmp->relative)
			return (0);
		if (!convert && tmp->num < num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_ismax(t_ps *ps, int num)
{
	int		i;
	t_stack	*tmp;

	i = -1;
	tmp = ps->stack_A;
	while (++i < ps->items_A)
	{
		if (tmp->num > num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	ft_rotatestackA(t_ps *ps, int pos)
{
	int		dir;

	dir = (pos > (ps->items_A / 2));
	if (dir == 1)
	{
		pos = ps->items_A - pos;
		while (pos-- > 0)
			ft_revrotate(ps, 0, 1);
	}
	else
		while (pos-- > 0)
			ft_rotate(ps, 0, 1);
}

void	ft_sortstackA(t_ps *ps)
{
	t_stack	*tmp;
	int		pos;

	tmp = ps->stack_A;
	pos = 0;
	while (pos < ps->items_A)
	{
		if (ft_ismin(ps, tmp->num, 0))
			break ;
		tmp = tmp->next;
		pos++;
	}
	ft_rotatestackA(ps, pos);
}

int	ft_getinsertpos(t_ps *ps)
{
	int			pos;
	t_stack		*tmp;

	pos = 0;
	tmp = ps->stack_A;
	while (!(ps->stack_B->num < tmp->num && ps->stack_B->num > tmp->prev->num))
	{
		pos++;
		tmp = tmp->next;
	}
	return (pos);
}
