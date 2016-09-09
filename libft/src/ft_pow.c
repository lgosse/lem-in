/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 11:58:17 by lgosse            #+#    #+#             */
/*   Updated: 2016/04/06 13:02:44 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_pow(int nb, int power)
{
	int i;
	int res;

	i = 0;
	res = 1;
	if (power == 0)
		return (res);
	while (i < power)
	{
		res *= nb;
		i++;
	}
	return (res);
}
