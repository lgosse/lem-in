/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findpath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 14:35:30 by lgosse            #+#    #+#             */
/*   Updated: 2016/05/09 14:04:25 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	ft_seleccolor(int color, t_list *tmp)
{
	while (color > 6)
		color -= 6;
	if (color == 0)
		ft_printf("L%d-%s ", tmp->content_size,
			((t_room *)tmp->content)->name);
	if (color == 1)
		ft_printf("%[r,B]TL%d-%s ", tmp->content_size,
			((t_room *)tmp->content)->name);
	else if (color == 2)
		ft_printf("%[g,B]TL%d-%s ", tmp->content_size,
			((t_room *)tmp->content)->name);
	else if (color == 3)
		ft_printf("%[y,B]TL%d-%s ", tmp->content_size,
			((t_room *)tmp->content)->name);
	else if (color == 4)
		ft_printf("%[b,B]TL%d-%s ", tmp->content_size,
			((t_room *)tmp->content)->name);
	else if (color == 5)
		ft_printf("%[m,B]TL%d-%s ", tmp->content_size,
			((t_room *)tmp->content)->name);
	else if (color == 6)
		ft_printf("%[c,B]TL%d-%s ", tmp->content_size,
			((t_room *)tmp->content)->name);
}

static void	ft_print_move(t_list *tmp, t_parse *parse)
{
	if (parse->opt & 1)
		ft_seleccolor(((t_room *)tmp->content)->way, tmp);
	else
		ft_printf("L%d-%s ", tmp->content_size,
		((t_room *)tmp->content)->name);
	if (parse->opt & 1)
		ft_printf("%[0]T");
	((t_room *)tmp->content)->nb_ants++;
}

static void	ft_choosefirstpath(t_list *ants, t_room *start, t_parse *parse)
{
	t_room		*room;
	t_room		*mv;
	int			ok;

	ok = 0;
	while (ants)
	{
		if (((t_room *)ants->content)->id == 1)
		{
			room = ants->content;
			if (((mv = ft_getroomwbalance(start->pipes, 0)) && mv->ok != -1
				&& mv->id != 0) ||
				((mv = ft_getroomwid(start->pipes, 0)) && ok == 0 &&
				mv->ok != -1 && (ok = 1)))
			{
				room->nb_ants--;
				ants->content = mv;
				ft_print_move(ants, parse);
			}
		}
		ants = ants->next;
	}
}

static void	ft_findpath(t_list *ants, t_double_room *dr, int nb_ants,
		t_parse *parse)
{
	t_list	*tmp;
	t_room	*room;

	while (dr->end->nb_ants != nb_ants)
	{
		tmp = ants;
		while (tmp)
		{
			room = tmp->content;
			if (room->way != 0)
				if (ft_getroomwway(room->pipes, room->way))
				{
					tmp->content = ft_getroomwway(room->pipes, room->way);
					room->nb_ants--;
					ft_print_move(tmp, parse);
				}
			tmp = tmp->next;
		}
		if (dr->start->nb_ants)
			ft_choosefirstpath(ants, dr->start, parse);
		if (parse->opt & 2)
			ft_printf("\nAnts at end : %d", dr->end->nb_ants);
		ft_printf("\n");
	}
}

void		ft_initants(int nb_ants, t_list *map, t_parse *parse)
{
	t_list			*ants;
	t_list			*tmp;
	t_double_room	double_room;
	int				i;

	i = nb_ants;
	ants = NULL;
	double_room.start = ft_getroomwid(map, 1);
	double_room.end = ft_getroomwid(map, 0);
	double_room.start->nb_ants = nb_ants;
	while (i > 0)
	{
		tmp = NULL;
		tmp = (t_list *)malloc(sizeof(t_list));
		tmp->content = double_room.start;
		tmp->content_size = i;
		ft_lstadd(&ants, tmp);
		i--;
	}
	ft_findpath(ants, &double_room, nb_ants, parse);
	ft_lstdelbyfunc(&ants, NULL);
}
