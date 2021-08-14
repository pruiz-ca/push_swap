/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 17:11:27 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/07/31 14:02:12 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_checkerKO(void)
{
	ft_putstr_fd("KO\n", 1);
	exit (0);
}

void	ft_checkeractionhub(t_ps *ps, char *action)
{
	if (!ft_strncmp(action, "sa", 3))
		ft_swap(ps, 0, 0);
	else if (!ft_strncmp(action, "sb", 3))
		ft_swap(ps, 1, 0);
	else if (!ft_strncmp(action, "ss", 3))
		ft_swap(ps, 2, 0);
	else if (!ft_strncmp(action, "pb", 3))
		ft_push(ps, 0, 0);
	else if (!ft_strncmp(action, "pa", 3))
		ft_push(ps, 1, 0);
	else if (!ft_strncmp(action, "ra", 3))
		ft_rotate(ps, 0, 0);
	else if (!ft_strncmp(action, "rb", 3))
		ft_rotate(ps, 1, 0);
	else if (!ft_strncmp(action, "rr", 3))
		ft_rotate(ps, 2, 0);
	else if (!ft_strncmp(action, "rra", 4))
		ft_revrotate(ps, 0, 0);
	else if (!ft_strncmp(action, "rrb", 4))
		ft_revrotate(ps, 1, 0);
	else if (!ft_strncmp(action, "rrr", 4))
		ft_revrotate(ps, 2, 0);
	else
		ft_error();
}

/*
** Function to read each line and check if every number is smaller than
** the next. I iterate until the second last so we avoid checking the last
** number with the first number.
*/
void	ft_checker(t_ps *ps)
{
	char	*action;
	int		i;

	while (get_next_line(STDIN_FILENO, &action) > 0)
	{
		ft_checkeractionhub(ps, action);
		free(action);
	}
	free(action);
	if (ps->items_B)
		ft_checkerKO();
	i = -1;
	while (++i < ps->items_A - 1)
	{
		if (ps->stack_A->num > ps->stack_A->next->num)
			ft_checkerKO();
		ps->stack_A = ps->stack_A->next;
	}
	ft_putstr_fd("OK\n", 1);
}

int	main(int argc, char **argv)
{
	t_ps	ps;

	if (argc < 2)
		return (0);
	ft_initvars(&ps);
	if (argc == 2)
		ft_parseone(&ps, argv[1]);
	else
		ft_parsemulti(&ps, argv);
	ft_checkduplicates(&ps);
	ft_checker(&ps);
	ft_freelist(&ps);
	return (0);
}
