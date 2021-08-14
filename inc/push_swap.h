/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 12:28:14 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/07/31 02:00:44 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <limits.h>
# include "../libft/libft.h"

# define PRINTMOVES 1
# define NOCOL "\001\e[0m\002"
# define RED "\001\e[0;31m\002"
# define GRN "\001\e[0;32m\002"
# define YEL "\001\e[0;33m\002"
# define BLU "\001\e[0;34m\002"
# define MAG "\001\e[0;35m\002"
# define CYN "\001\e[0;36m\002"
# define WHT "\001\e[0;37m\002"

typedef struct s_stack
{
	int					num;
	int					relative;
	struct s_stack		*next;
	struct s_stack		*prev;
}						t_stack;

typedef struct s_ps
{
	int					items_A;
	int					items_B;
	t_stack				*stack_A;
	t_stack				*stack_B;
	int					mustswap;
	int					chunk;
}						t_ps;

/* PARSE */
void		ft_checkduplicates(t_ps *pswap);
void		ft_checkargv(char *argv);
void		ft_checknum(char *argv, int sp_allow);
void		ft_parseone(t_ps *pswap, char *argv);
void		ft_parsemulti(t_ps *pswap, char **argv);

/* UTILS */
void		ft_error(void);
int			ft_issorted(t_ps *ps);
void		ft_initvars(t_ps *ps);

/* ACTIONS */
void		ft_swap(t_ps *ps, int rot, int print);
void		ft_push(t_ps *ps, int rot, int print);
void		ft_rotate(t_ps *ps, int rot, int print);
void		ft_revrotate(t_ps *ps, int rot, int print);

/* PS_LIB */
void		ft_swaplistnodes(t_stack *first, t_stack *second);
void		ft_insertnode(t_stack **src, t_stack **dst);
void		ft_numaddback(t_stack **lst, t_stack *new);
void		ft_numaddfront(t_stack **lst, t_stack *new);
void		ft_freelist(t_ps *ps);

/* SORT SMALL UTILS */
int			ft_ismin(t_ps *ps, int num, int convert);
int			ft_ismax(t_ps *ps, int num);
void		ft_rotatestackA(t_ps *ps, int pos);
void		ft_sortstackA(t_ps *ps);
int			ft_getinsertpos(t_ps *ps);

/* SORT SMALL */
void		ft_insert5numbers(t_ps *ps);
void		ft_sort5numbers(t_ps *ps);
void		ft_sort3numbers(t_ps *ps);
void		ft_sorthub(t_ps *ps);

/* SORT BIG UTILS */
void		ft_chunkcalculator(t_ps *ps);
int			ft_foundnext(t_ps *ps, int num);
void		ft_rotatestackB(t_ps *ps, int pos, int num);

/* SORT BIG */
void		ft_convertnums(t_ps *ps);
void		ft_createchunks(t_ps *ps);
void		ft_getnumtotop(t_ps *ps, int num);
void		ft_sendbackinorder(t_ps *ps);
void		ft_sortbig(t_ps *ps);

/* BONUS */
void		ft_checkerKO(void);
void		ft_checkeractionhub(t_ps *ps, char *action);
void		ft_checker(t_ps *ps);

#endif
