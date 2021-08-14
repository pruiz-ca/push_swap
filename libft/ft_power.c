/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 02:12:22 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/07/30 21:52:09 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_power(double num, double pow)
{
	double		result;

	result = 1;
	while (pow-- > 0)
		result *= num;
	return (result);
}
