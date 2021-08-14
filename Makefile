# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pruiz-ca <pruiz-ca@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/01 14:07:20 by pruiz-ca          #+#    #+#              #
#    Updated: 2021/08/14 13:58:20 by pruiz-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL		=	/bin/bash

NAME		=	push_swap
NAME_BONUS	=	checker

S			=	src/
O			=	obj/
I			=	inc/
B			=	bonus/

NOCOL		=	\033[0m
RED			=	\033[1;31m
ORG			=	\033[0;33m
YEL			=	\033[1;33m
GRN			=	\033[1;32m
BLU			=	\033[0;34m
CYN			=	\033[0;36m

SRCS		=	$Smain.c
OBJS		=	$(SRCS:$S%.c=$O%.o)

COMMON		=	$Sparse.c $Sutils.c $Sactions.c $Sps_lib.c $Ssort_small.c \
				$Ssort_big.c $Ssort_small_utils.c $Ssort_big_utils.c
COMMON_OBJS	=	$(COMMON:$S%.c=$O%.o)

SRCS_BONUS	=	$Bmain_bonus.c
OBJS_BONUS	=	$(SRCS_BONUS:$B%.c=$O%.o)

HEADER		=	-I inc/

LIBFT		=	-L libft -lft

CC			=	clang #-fsanitize=address

FLAGS		=	-Wall -Wextra -Werror

ECHO		=	echo -e

start:
				@[[ -d "$(O)" && -f "$(NAME)" ]] || echo -e -n "$(ORG)[Dependecies]:\t$(NOCOL)"
				@make -s all

all:			$(NAME)

$(NAME):		$(OBJS) $(COMMON_OBJS)
				@echo -e -n "$(GRN) => Success!$(NOCOL)"
				@$(ECHO) -n "\n$(ORG)[Libft]:\t$(NOCOL)"
				@make -s -C libft
				@echo -e -n "$(GRN) => Success! $(NOCOL)"
				@$(ECHO) -n "\n$(ORG)[$(NAME)]:\t$(NOCOL)"
				@$(CC) $(FLAGS) $(SRCS) $(COMMON) $(HEADER) $(LIBFT) -o $(NAME)
				@$(ECHO) "$(GRN) => Success!$(NOCOL)"

$O%.o: 			$S%.c
				@[ -d $(O) ] || mkdir -p $(O)
				@echo -e -n "$(ORG)*$(NOCOL)"
				@$(CC) $(CFLAGS) -c $< $(HEADER) -o $@

$O%.o: 			$B%.c
				@[ -d $(O) ] || mkdir -p $(O)
				@echo -e -n "$(ORG)*$(NOCOL)"
				@$(CC) $(CFLAGS) -c $< $(HEADER) -o $@

clean:
				@rm -rf $(O)
				@make clean -C libft >/dev/null

fclean:			clean
				@rm -f $(NAME)
				@rm -f $(NAME_BONUS)
				@rm -rf *.dSYM
				@rm -f libft/libft.a
				@find . -name ".DS_Store" -delete

re:				fclean all

bonus:
				@[[ -d "$(O)" && -f "$(NAME_BONUS)" ]] || echo -e -n "$(ORG)[Dependecies]:\t$(NOCOL)"
				@make -s allbonus

allbonus:		$(NAME_BONUS)

$(NAME_BONUS):	$(OBJS_BONUS) $(COMMON_OBJS)
				@echo -e -n "$(GRN) => Success!$(NOCOL)"
				@$(ECHO) -n "\n$(ORG)[Libft]:\t$(NOCOL)"
				@make -s -C libft
				@$(ECHO) -n "\n$(ORG)[$(NAME_BONUS)]:\t$(NOCOL)"
				@$(CC) $(FLAGS) $(SRCS_BONUS) $(COMMON) $(HEADER) $(LIBFT) -o $(NAME_BONUS)
				@$(ECHO) "$(GRN) => Success!$(NOCOL)"

norm:
				@clear
				@$(ECHO) "$(PUR)=> Norminette <=$(NOCOL)"
				@$(ECHO) "$(PUR)  ------------$(NOCOL)"
				@norminette src inc libft bonus

.PHONY:			all clean fclean re bonus norm
