/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 16:43:01 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/07/31 02:20:52 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_chunkcalculator(t_ps *ps)
{
	int	result;

	result = 0;
	if (ps->items_A > 1)
	{
		result = (3 * (ps->items_A) / 40) + (45 / 2);
		while (result % 5 != 0)
			result += 1;
	}
	ps->chunk = result;
}

int	ft_foundnext(t_ps *ps, int num)
{
	if (ps->stack_B->num == num && !ps->mustswap)
	{
		ft_push(ps, 1, PRINTMOVES);
		ps->mustswap = 1;
		return (1);
	}
	return (0);
}

void	ft_rotatestackB(t_ps *ps, int pos, int num)
{
	int		dir;

	dir = (pos > (ps->items_B / 2));
	if (dir == 1)
	{
		while (ps->stack_B->num != num)
		{
			if (!ft_foundnext(ps, num - 1))
				ft_revrotate(ps, 1, PRINTMOVES);
		}
	}
	else
	{
		while (ps->stack_B->num != num)
		{
			if (!ft_foundnext(ps, num - 1))
				ft_rotate(ps, 1, PRINTMOVES);
		}
	}
}
