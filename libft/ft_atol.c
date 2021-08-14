/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 20:02:27 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/07/30 21:50:59 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t	ft_atol(const char *str)
{
	int			sign;
	intmax_t	num;
	int			i;

	sign = 1;
	num = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (num * sign >= INTMAX_MAX)
			return (INTMAX_MAX);
		else if (num * sign <= INTMAX_MIN)
			return (INTMAX_MIN);
		num = (num * 10) + str[i] - '0';
		i++;
	}
	return (sign * num);
}
