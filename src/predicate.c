/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   predicate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 11:33:44 by lgosse            #+#    #+#             */
/*   Updated: 2016/05/14 12:32:48 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_ismapvalid(t_list *map)
{
	int			ok;
	t_room		*room;
	t_list		*tmp;

	ok = 0;
	room = ft_getroomwid(map, 1);
	tmp = room->pipes;
	while (tmp)
	{
		room = tmp->content;
		if (room->way != 0 || room->id == 0)
			ok++;
		tmp = tmp->next;
	}
	if (ok && (ok = 0) + 1)
		while (map)
		{
			room = map->content;
			if (room->id == 0 || room->id == 1)
				ok++;
			map = map->next;
		}
	return (ok);
}

int		ft_seemshillvalid(t_list *map)
{
	t_room		*act;
	int			start;
	int			end;

	end = 0;
	start = 0;
	while (map)
	{
		act = map->content;
		if (act->id == 0)
		{
			if (act->pipes != NULL)
				end++;
		}
		else if (act->id == 1)
			if (act->pipes != NULL)
				start++;
		map = map->next;
	}
	if (start == 1 && end == 1)
		return (1);
	ft_printf("%d %d\n", start, end);
	return (0);
}

int		ft_ispipevalid(t_room *r1, t_room *r2)
{
	t_list	*tmp;

	tmp = r1->pipes;
	while (tmp)
	{
		if (!ft_strcmp(((t_room *)tmp->content)->name, r2->name))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
