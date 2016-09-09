/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invaliduselessways.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 14:10:24 by lgosse            #+#    #+#             */
/*   Updated: 2016/05/07 18:15:19 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		ft_invaliduselessways(t_list *map)
{
	int			way;
	t_room		*start;
	t_room		*keep;
	t_room		*tmp;

	way = 1;
	start = ft_getroomwid(map, 1);
	while (ft_getroomwway(start->pipes, way))
	{
		map = start->pipes;
		keep = ft_getroomwbalance(start->pipes, way);
		if (keep == NULL)
			break ;
		while (map)
		{
			tmp = map->content;
			if (tmp->way == way && tmp != keep)
				tmp->way = -1;
			map = map->next;
		}
		way++;
	}
}
