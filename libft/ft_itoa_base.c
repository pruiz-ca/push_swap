/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 13:45:38 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/07/30 21:51:59 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long	ft_abs(int n)
{
	if (n < 0)
		n = n * -1;
	return (n);
}

static int	ft_int_count(int n, int base)
{
	int				i;
	unsigned int	u;
	unsigned int	ubase;

	i = 1;
	ubase = (unsigned int)base;
	u = n;
	while ((u >= ubase) > 0)
	{
		u /= ubase;
		i++;
	}
	return (i);
}

char	*ft_itoa_base(int n, unsigned long base)
{
	char			*str;
	int				len;
	int				i;
	unsigned int	u;

	len = ft_int_count(n, base);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	u = n;
	str[len] = '\0';
	while (len > i)
	{
		if (u % base < 10)
			str[--len] = ft_abs(u % base) + '0';
		else
			str[--len] = ft_abs(u % base) - 10 + 'a';
		u /= base;
	}
	return (str);
}
