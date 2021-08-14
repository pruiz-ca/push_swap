/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecscadiv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 22:33:29 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/07/30 21:52:30 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector	ft_vecscadiv(t_vector v, double s)
{
	t_vector	ans;

	ans.x = v.x / s;
	ans.y = v.y / s;
	ans.z = v.z / s;
	return (ans);
}