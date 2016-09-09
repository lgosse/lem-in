/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setants.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 12:47:39 by lgosse            #+#    #+#             */
/*   Updated: 2016/05/13 17:19:53 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visu.h"

static void		ft_putant(t_visu *visu, t_pos *pos1, t_pos *pos2, t_list *ant)
{
	if (ft_abs(pos2->x - pos1->x) >= ft_abs(pos2->y - pos1->y))
	{
		if ((pos2->x - pos1->x > 0 && (pos2->y != pos1->y)) ||
			((pos1->x < pos2->x) && pos2->y == pos1->y))
			ft_placeant(visu, pos1, pos2, ant);
		else
			ft_placeant3(visu, pos2, pos1, ant);
	}
	else if ((pos2->y - pos1->y > 0 && (pos2->x != pos1->x)) ||
		((pos1->y < pos2->y) && pos2->x == pos1->x))
		ft_placeant2(visu, pos1, pos2, ant);
	else
		ft_placeant4(visu, pos2, pos1, ant);
}

void			ft_print_ants(t_visu *visu, t_list *ants)
{
	t_list	*tmp;
	t_ant	*truc;
	t_pos	pos1;
	t_pos	pos2;

	if (ft_isanimend(ants) == 0)
	{
		tmp = ants;
		while (tmp)
		{
			pos1.x = ((t_ant *)tmp->content)->x1;
			pos1.y = ((t_ant *)tmp->content)->y1;
			pos2.x = ((t_ant *)tmp->content)->x2;
			pos2.y = ((t_ant *)tmp->content)->y2;
			ft_putant(visu, &pos1, &pos2, tmp);
			if (((t_ant *)tmp->content)->end)
			{
				truc = tmp->content;
				((t_list *)truc->ant)->content = truc->room;
			}
			tmp = tmp->next;
		}
		if (ft_isanimend(ants))
			visu->action = -1;
	}
}

void			ft_setants(t_list **ants, t_room *room, t_list *ant)
{
	t_ant	*newant;
	t_list	*new;

	if (room && ant)
		if ((newant = (t_ant *)malloc(sizeof(t_ant))))
		{
			newant->x1 = ((t_room *)ant->content)->x * 25 + 38;
			newant->y1 = ((t_room *)ant->content)->y * 25 + 13;
			newant->actx = newant->x1;
			newant->acty = newant->y1;
			newant->x2 = room->x * 25 + 38;
			newant->y2 = room->y * 25 + 13;
			newant->end = 0;
			newant->ant = ant;
			newant->room = room;
			new = (t_list *)malloc(sizeof(t_list));
			new->content = newant;
			ft_lstadd(ants, new);
		}
}
