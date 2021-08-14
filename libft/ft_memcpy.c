/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 17:16:26 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/07/30 21:52:08 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*str;
	int				i;

	str = (unsigned char *)dst;
	i = 0;
	if (dst == NULL && src == NULL && n)
		return (dst);
	while (i < (int)n)
	{
		str[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}
