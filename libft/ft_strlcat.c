/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 20:28:25 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/07/30 21:52:18 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	src_size;
	unsigned int	dest_size;
	unsigned int	i;

	src_size = ft_strlen(src);
	dest_size = ft_strlen(dst);
	i = 0;
	if (dstsize <= dest_size)
		return (dstsize + src_size);
	while (*dst)
		dst++;
	while ((i < dstsize - dest_size - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_size + dest_size);
}
