/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 20:17:06 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/07/30 21:52:18 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = 0;
	if (!dst || !src)
		return (0);
	while (*src)
	{
		if (len < dstsize)
		{
			if (i == dstsize - 1)
				*dst = '\0';
			else
				*dst = *src;
			i++;
		}
		src++;
		dst++;
		len++;
	}
	if (dstsize == 0 || len > dstsize)
		return (len);
	*dst = '\0';
	return (i);
}
