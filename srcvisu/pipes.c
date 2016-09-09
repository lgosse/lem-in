/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 16:22:58 by lgosse            #+#    #+#             */
/*   Updated: 2016/05/13 17:17:48 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visu.h"

static void		ft_put_line(t_visu *visu, t_pos *pos1, t_pos *pos2, int color)
{
	int		x;
	int		y;
	t_pos	pos;

	x = pos1->x;
	while (x <= pos2->x)
	{
		if (pos1->x != pos2->x)
			y = pos1->y + ((pos2->y - pos1->y) * (x - pos1->x)) /
				(pos2->x - pos1->x);
		else
			y = pos2->y;
		pos.x = x;
		pos.y = y;
		ft_pixel_put_to_image(visu->mlx,
			visu->data + y * visu->sline + x * (visu->bpp / 8), color);
		x++;
	}
}

static void		ft_put_line2(t_visu *visu, t_pos *pos1, t_pos *pos2, int color)
{
	int		x;
	int		y;
	t_pos	pos;

	y = pos1->y;
	while (y <= pos2->y)
	{
		if (pos1->y != pos2->y)
			x = pos1->x + ((pos2->x - pos1->x) * (y - pos1->y)) /
				(pos2->y - pos1->y);
		else
			x = pos2->x;
		pos.x = x;
		pos.y = y;
		ft_pixel_put_to_image(visu,
			visu->data + y * visu->sline + x * (visu->bpp / 8), color);
		y++;
	}
}

static void		ft_draw_line(t_visu *visu, t_pos *pos1, t_pos *pos2, int color)
{
	if (ft_abs(pos2->x - pos1->x) > ft_abs(pos2->y - pos1->y))
	{
		if (pos2->x - pos1->x > 0)
			ft_put_line(visu, pos1, pos2, color);
		else
			ft_put_line(visu, pos2, pos1, color);
	}
	else if (pos2->y - pos1->y > 0)
		ft_put_line2(visu, pos1, pos2, color);
	else
		ft_put_line2(visu, pos2, pos1, color);
}

void			ft_print_pipes(t_visu *visu)
{
	t_list		*tmp;
	t_list		*tmp2;
	t_room		*room;
	t_pos		pos1;
	t_pos		pos2;

	tmp = visu->map;
	while (tmp)
	{
		room = tmp->content;
		pos1.x = room->x * 25 + 38;
		pos1.y = room->y * 25 + 13;
		tmp2 = room->pipes;
		while (tmp2)
		{
			room = tmp2->content;
			pos2.x = room->x * 25 + 38;
			pos2.y = room->y * 25 + 13;
			ft_draw_line(visu, &pos1, &pos2, 0x20C4BF);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}
