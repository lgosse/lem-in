/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlepipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 15:31:19 by lgosse            #+#    #+#             */
/*   Updated: 2016/05/07 18:02:44 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mapmaker.h"

void		ft_put_line(t_mmkr *mmkr, t_pos *pos1, t_pos *pos2, int color)
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
		if (x >= 25 && x < 975 && y >= 300 && y < 1275)
			mlx_pixel_put(mmkr->mlx, mmkr->win, x, y, color);
		x++;
	}
}

void		ft_put_line2(t_mmkr *mmkr, t_pos *pos1, t_pos *pos2, int color)
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
		if (x > 25 && x < 975 && y > 300 && y < 1275)
			mlx_pixel_put(mmkr->mlx, mmkr->win, x, y, color);
		y++;
	}
}

void		ft_draw_line(t_mmkr *mmkr, t_pos *pos1, t_pos *pos2, int color)
{
	if (ft_abs(pos2->x - pos1->x) > ft_abs(pos2->y - pos1->y))
	{
		if (pos2->x - pos1->x > 0)
			ft_put_line(mmkr, pos1, pos2, color);
		else
			ft_put_line(mmkr, pos2, pos1, color);
	}
	else if (pos2->y - pos1->y > 0)
		ft_put_line2(mmkr, pos1, pos2, color);
	else
		ft_put_line2(mmkr, pos2, pos1, color);
}

void		ft_print_pipes(t_mmkr *mmkr)
{
	t_list	*tmp;
	t_seg	*seg;
	t_pos	*pos1;
	t_pos	*pos2;

	seg = NULL;
	tmp = mmkr->pipes;
	while (tmp)
	{
		seg = tmp->content;
		pos1 = (t_pos *)malloc(sizeof(t_pos));
		pos2 = (t_pos *)malloc(sizeof(t_pos));
		pos1->x = seg->x1;
		pos1->y = seg->y1;
		pos2->x = seg->x2;
		pos2->y = seg->y2;
		ft_draw_line(mmkr, pos1, pos2, 0x20C4BF);
		ft_memdel((void **)&pos1);
		ft_memdel((void **)&pos2);
		tmp = tmp->next;
	}
}

void		ft_handlepipes(t_mmkr *mmkr, int x, int y, int button)
{
	if (button == 1)
	{
		if (mmkr->tab[y][x] && !mmkr->pos1)
		{
			mmkr->pos1 = (t_pos *)malloc(sizeof(t_pos));
			mmkr->pos1->x = x * 25 + 38;
			mmkr->pos1->y = y * 25 + 312;
			ft_draw_line(mmkr, mmkr->pos1, mmkr->pos_crs, 0xFF0000);
		}
		else if (mmkr->tab[y][x] && mmkr->pos1 &&
			(((mmkr->pos1->x - 25) / 25) != x |
			((mmkr->pos1->y - 300) / 25) != y))
		{
			mmkr->pos2 = (t_pos *)malloc(sizeof(t_pos));
			mmkr->pos2->x = x * 25 + 38;
			mmkr->pos2->y = y * 25 + 312;
			ft_createpipe(mmkr);
			ft_reinit_window(mmkr);
			ft_print_pipes(mmkr);
		}
	}
}
