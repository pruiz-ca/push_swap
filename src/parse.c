/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 11:30:00 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/07/30 21:50:14 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Checks one character with the next ones to avoid repetitions.
*/
void	ft_checkduplicates(t_ps *ps)
{
	t_stack		*tmp;
	int			i;
	int			j;

	i = -1;
	while (++i < ps->items_A)
	{
		j = 0;
		tmp = ps->stack_A->next;
		while (++j < ps->items_A - i)
		{
			if (ps->stack_A->num == tmp->num)
				ft_error();
			tmp = tmp->next;
		}
		ps->stack_A = ps->stack_A->next;
	}
}

/*
** Checks for spaces at the beginning and at the end. Also one space between
** numbers.
*/
void	ft_checkargv(char *argv)
{
	int		i;

	i = -1;
	while (argv[++i])
	{
		if (argv[i + 1] && argv[i] == ' ' && argv[i + 1] == ' ')
			ft_error();
		if (argv[0] == ' ' || (!argv[i + 1] && argv[i] == ' '))
			ft_error();
	}
}

/*
** Only numbers, spaces and signs are allowed, but only in the correct places.
** Signs just before a number, only one space between numbers.
*/
void	ft_checknum(char *argv, int sp_allow)
{
	int		i;

	i = -1;
	while (argv[++i])
	{
		if (!sp_allow && argv[i] == ' ')
			ft_error();
		if (!ft_isdigit(argv[i]) && argv[i] != ' '
			&& argv[i] != '+' && argv[i] != '-')
			ft_error();
		if ((argv[i] == '-' && i != 0) || (argv[i] == '+' && i != 0))
			ft_error();
		if ((argv[i] == '+' || argv[i] == '-') && !ft_isdigit(argv[i + 1]))
			ft_error();
		if (ft_strlen(argv) > 11
			|| ft_atol(argv) > INT_MAX || ft_atol(argv) < INT_MIN)
			ft_error();
	}
}

/*
** Parser if input is one string between quotes. Saves the result in a
** double circular linked list.
*/
void	ft_parseone(t_ps *ps, char *argv)
{
	char		**split;
	t_stack		*new;
	int			i;

	i = -1;
	ft_checkargv(argv);
	split = ft_split(argv, ' ');
	ps->stack_A = NULL;
	while (split[++i])
	{
		ft_checknum(split[i], 1);
		new = malloc(sizeof(t_stack));
		new->num = ft_atoi(split[i]);
		new->relative = 0;
		new->next = NULL;
		new->prev = NULL;
		ft_numaddback(&ps->stack_A, new);
	}
	ps->items_A = i;
	ft_freetab(split);
}

/*
** Parser if input is multiple arguments, being each a number.
** Saves the result in a double circular linked list.
** Since the first number starts in argv[1], I have to start at i = 0 and
** substract one from the items counter.
*/
void	ft_parsemulti(t_ps *ps, char **argv)
{
	t_stack		*new;
	int			i;

	i = 0;
	ps->stack_A = NULL;
	while (argv[++i])
	{
		ft_checknum(argv[i], 0);
		new = malloc(sizeof(t_stack));
		new->num = ft_atoi(argv[i]);
		new->relative = 0;
		new->next = NULL;
		new->prev = NULL;
		ft_numaddback(&ps->stack_A, new);
	}
	ps->items_A = i - 1;
}
