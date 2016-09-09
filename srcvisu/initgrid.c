/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initgrid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 14:28:03 by lgosse            #+#    #+#             */
/*   Updated: 2016/05/11 14:01:27 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visu.h"

void	ft_colorcase(t_visu *visu, int x, int y, int color)
{
	int		x2;
	int		y2;
	int		tmp;

	if (color == 0)
		color = 0xFF0000;
	else if (color == 1)
		color = 0xFFFFFF;
	else
		color = 0xaeee00;
	x = x * 25 + 26;
	y = y * 25 + 1;
	tmp = y;
	x2 = x + 25;
	y2 = y + 25;
	while (x < x2 - 1)
	{
		y = tmp - 1;
		while (++y < y2 - 1)
		{
			ft_pixel_put_to_image(visu,
				visu->data + y * visu->sline + x * (visu->bpp / 8), color);
		}
		x++;
	}
}

int		ft_initrooms(t_visu *visu)
{
	t_list	*tmp;
	t_room	*room;

	tmp = visu->map;
	while (tmp)
	{
		room = tmp->content;
		if (room->y >= 0 && room->y < 39 && room->x >= 0 && room->x < 39)
			ft_colorcase(visu, room->x, room->y, room->id);
		else
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	ft_initgrid(t_visu *visu)
{
	int		x;
	int		y;

	y = 25;
	while (y <= 975)
	{
		x = 24;
		while (++x <= 975)
			ft_pixel_put_to_image(visu,
				visu->data + y * visu->sline + x * (visu->bpp / 8), 0xffffff);
		y += 25;
	}
	x = 25;
	while (x <= 975)
	{
		y = -1;
		while (++y <= 975)
			ft_pixel_put_to_image(visu,
				visu->data + y * visu->sline + x * (visu->bpp / 8), 0xffffff);
		x += 25;
	}
}
