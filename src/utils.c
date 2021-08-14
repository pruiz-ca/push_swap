/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 09:57:46 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/07/31 00:05:43 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit (1);
}

int	ft_issorted(t_ps *ps)
{
	int			i;
	t_stack		*tmp;

	i = 0;
	tmp = ps->stack_A;
	while (++i < ps->items_A)
	{
		if (tmp->num > tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	ft_initvars(t_ps *ps)
{
	ps->stack_A = NULL;
	ps->stack_B = NULL;
	ps->items_A = 0;
	ps->items_B = 0;
	ps->mustswap = 0;
	ps->chunk = 0;
}
