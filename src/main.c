/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 14:37:49 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/07/31 02:00:40 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ps	ps;

	ft_initvars(&ps);
	if (argc == 1)
		return (0);
	else if (argc == 2)
		ft_parseone(&ps, argv[1]);
	else
		ft_parsemulti(&ps, argv);
	ft_checkduplicates(&ps);
	ft_chunkcalculator(&ps);
	ft_sorthub(&ps);
	ft_freelist(&ps);
	return (0);
}
