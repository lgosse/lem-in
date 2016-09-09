/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placeant.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 17:03:11 by lgosse            #+#    #+#             */
/*   Updated: 2016/05/13 17:19:15 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visu.h"

void		ft_placeant(t_visu *visu, t_pos *pos1, t_pos *pos2, t_list *ant)
{
	int		x;
	int		y;

	x = ((t_ant *)ant->content)->actx;
	if (((t_ant *)ant->content)->end == 0)
		x += 1;
	if (((t_ant *)ant->content)->actx == pos2->x &&
		((t_ant *)ant->content)->acty == pos2->y)
		((t_ant *)ant->content)->end = 1;
	if (pos1->x != pos2->x)
		y = pos1->y + ((pos2->y - pos1->y) * (x - pos1->x)) /
			(pos2->x - pos1->x);
	else
		y = pos2->y;
	((t_ant *)ant->content)->actx = x;
	((t_ant *)ant->content)->acty = y;
	if (x >= 25 && x < 975 && y >= 0 && y < 975)
	{
		mlx_put_image_to_window(visu->mlx, visu->win, visu->imgant,
			x - 24, y - 16);
	}
}

void		ft_placeant2(t_visu *visu, t_pos *pos1, t_pos *pos2, t_list *ant)
{
	int		x;
	int		y;

	y = ((t_ant *)ant->content)->acty;
	if (((t_ant *)ant->content)->end == 0)
		y += 1;
	if (((t_ant *)ant->content)->acty == pos2->y &&
		((t_ant *)ant->content)->actx == pos2->x)
		((t_ant *)ant->content)->end = 1;
	if (pos1->y != pos2->y)
		x = pos1->x + ((pos2->x - pos1->x) * (y - pos1->y)) /
			(pos2->y - pos1->y);
	else
		x = pos2->x;
	((t_ant *)ant->content)->actx = x;
	((t_ant *)ant->content)->acty = y;
	if (x > 25 && x < 975 && y > 0 && y < 975)
		mlx_put_image_to_window(visu->mlx, visu->win, visu->imgant,
			x - 24, y - 16);
}

void		ft_placeant3(t_visu *visu, t_pos *pos1, t_pos *pos2, t_list *ant)
{
	int		x;
	int		y;

	x = ((t_ant *)ant->content)->actx;
	if (((t_ant *)ant->content)->end == 0)
		x -= 1;
	if (((t_ant *)ant->content)->actx == pos1->x &&
		((t_ant *)ant->content)->acty == pos1->y)
		((t_ant *)ant->content)->end = 1;
	if (pos1->x != pos2->x)
		y = pos1->y + ((pos2->y - pos1->y) * (x - pos1->x)) /
			(pos2->x - pos1->x);
	else
		y = pos2->y;
	((t_ant *)ant->content)->actx = x;
	((t_ant *)ant->content)->acty = y;
	if (x >= 25 && x < 975 && y >= 0 && y < 975)
		mlx_put_image_to_window(visu->mlx, visu->win, visu->imgant,
			x - 24, y - 16);
}

void		ft_placeant4(t_visu *visu, t_pos *pos1, t_pos *pos2, t_list *ant)
{
	int		x;
	int		y;

	y = ((t_ant *)ant->content)->acty;
	if (((t_ant *)ant->content)->end == 0)
		y -= 1;
	if (((t_ant *)ant->content)->acty == pos1->y &&
		((t_ant *)ant->content)->actx == pos1->x)
		((t_ant *)ant->content)->end = 1;
	if (pos1->y != pos2->y)
		x = pos1->x + ((pos2->x - pos1->x) * (y - pos1->y)) /
			(pos2->y - pos1->y);
	else
		x = pos2->x;
	((t_ant *)ant->content)->actx = x;
	((t_ant *)ant->content)->acty = y;
	if (x > 25 && x < 975 && y > 0 && y < 975)
		mlx_put_image_to_window(visu->mlx, visu->win, visu->imgant,
			x - 24, y - 16);
}
