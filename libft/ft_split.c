/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 15:58:06 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/07/30 21:52:14 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_string_count(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s[j] && s[j] != c)
		i = 1;
	while (s[j])
	{
		if (s[j] == c && s[j + 1] != c && s[j + 1])
			i++;
		j++;
	}
	return (i);
}

static char	*ft_get_split(char const *str, char c, int start)
{
	int		i;
	int		end;
	char	*segment;

	while (str[start] == c && str[start])
		start++;
	end = start;
	while (str[end] != c && str[end])
		end++;
	segment = (char *)malloc(sizeof(char) * (end - start) + 1);
	if (!segment)
		return (NULL);
	i = 0;
	while (start + i < end)
	{
		segment[i] = str[start + i];
		i++;
	}
	segment[i] = '\0';
	return (segment);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**tab;
	int		i;
	int		start;

	if (!s)
		return (NULL);
	count = ft_string_count(s, c);
	tab = (char **)malloc(sizeof(char *) * (count + 1));
	if (!tab)
		return (NULL);
	i = 0;
	start = 0;
	while (s[start] == c)
		start++;
	while (i < count)
	{
		tab[i] = ft_get_split(s, c, start);
		while (s[start] == c)
			start++;
		start += ft_strlen(tab[i]);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
