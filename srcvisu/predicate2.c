/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   predicate2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 15:13:05 by lgosse            #+#    #+#             */
/*   Updated: 2016/05/12 15:32:49 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visu.h"

int		ft_isanimend(t_list *ants)
{
	t_ant *ant;

	while (ants)
	{
		ant = ants->content;
		if (ant->end == 0)
			return (0);
		ants = ants->next;
	}
	return (1);
}
