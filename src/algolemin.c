/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algolemin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 17:14:10 by lgosse            #+#    #+#             */
/*   Updated: 2016/05/09 10:58:27 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	ft_balance(t_room *room, int way, int weight)
{
	t_list		*pipes;

	if (room->id == 0)
		return ;
	if (room->id == 1)
	{
		room->ok = weight;
		return ;
	}
	if (room->ok == -1 || room->ok > weight)
	{
		room->way = way;
		room->ok = weight;
	}
	else
		return ;
	pipes = room->pipes;
	while (pipes)
	{
		ft_balance(pipes->content, way, weight + 1);
		pipes = pipes->next;
	}
}

void		ft_initpond(t_list *map)
{
	t_room		*end;
	t_list		*pipes;
	int			way;

	end = map->content;
	way = 1;
	while (end->id != 0)
	{
		map = map->next;
		end = map->content;
	}
	pipes = end->pipes;
	end->ok = 1;
	while (pipes)
	{
		ft_balance(pipes->content, way, 2);
		way++;
		pipes = pipes->next;
	}
}
