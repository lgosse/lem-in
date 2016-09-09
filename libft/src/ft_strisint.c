/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 14:39:39 by lgosse            #+#    #+#             */
/*   Updated: 2016/03/09 14:39:52 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_return(char *int_min, char *int_max, int ret)
{
	free(int_min);
	free(int_max);
	return (ret);
}

int		ft_strisint(char *nbr)
{
	int		i;
	char	*int_min;
	char	*int_max;

	i = -1;
	int_min = ft_itoa(INT_MIN);
	int_max = ft_itoa(INT_MAX);
	if ((nbr[0] != '-' && ft_strlen(nbr) < ft_strlen(int_max)) ||
		(nbr[0] == '-' && ft_strlen(nbr) < ft_strlen(int_min)))
		return (ft_return(int_min, int_max, 1));
	else if ((nbr[0] != '-' && ft_strlen(nbr) > ft_strlen(int_max)) ||
			(nbr[0] == '-' && ft_strlen(nbr) > ft_strlen(int_min)))
		return (ft_return(int_min, int_max, 0));
	if (nbr[0] == '-' && ++i + 1)
		while (nbr[++i] != '\0')
			if (nbr[i] > int_min[i])
				return (ft_return(int_min, int_max, 0));
	if (nbr[0] != '-')
		while (nbr[++i] != '\0')
			if (nbr[i] > int_max[i])
				return (ft_return(int_min, int_max, 0));
	if (nbr[i] == '\0')
		return (ft_return(int_min, int_max, 1));
	return (ft_return(int_min, int_max, 0));
}
