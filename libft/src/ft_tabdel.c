/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 14:45:40 by mbuclin           #+#    #+#             */
/*   Updated: 2016/04/13 17:29:27 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_tabdel(void **todel)
{
	int		i;

	i = 0;
	if (todel)
	{
		while (todel[i])
		{
			free(todel[i]);
			todel[i] = NULL;
			i++;
		}
		free(todel);
		todel = NULL;
	}
}
