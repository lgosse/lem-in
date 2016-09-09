/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlegrid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 15:17:50 by lgosse            #+#    #+#             */
/*   Updated: 2016/05/09 12:02:48 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mapmaker.h"

void		ft_colorcase(t_mmkr *mmkr, int x, int y, int color)
{
	int		x2;
	int		y2;
	int		tmp;

	if (color == 1)
		color = 0xaeee00;
	else if (color == 2)
		color = 0xFFFFFF;
	else if (color == 3)
		color = 0xFF0000;
	x = x * 25 + 26;
	y = y * 25 + 301;
	tmp = y;
	x2 = x + 25;
	y2 = y + 25;
	while (x < x2 - 1)
	{
		y = tmp;
		while (y < y2 - 1)
		{
			mlx_pixel_put(mmkr->mlx, mmkr->win, x, y, color);
			y++;
		}
		x++;
	}
}

void		ft_reinit_window(t_mmkr *mmkr)
{
	mlx_clear_window(mmkr->mlx, mmkr->win);
	mlx_put_image_to_window(mmkr->mlx, mmkr->win, mmkr->img, 0, 300);
	mlx_put_image_to_window(mmkr->mlx, mmkr->win, mmkr->hud, 0, 0);
	mlx_string_put(mmkr->mlx, mmkr->win, 60, 25, 0xFFFFFF, "Empty room");
	mlx_string_put(mmkr->mlx, mmkr->win, 60, 75, 0xFFFFFF, "Start room");
	mlx_string_put(mmkr->mlx, mmkr->win, 60, 125, 0xFFFFFF, "End room");
	mlx_string_put(mmkr->mlx, mmkr->win, 25, 225, 0xFFFFFF,
		"Right click : delete room");
	mlx_string_put(mmkr->mlx, mmkr->win, 25, 250, 0xFFFFFF,
		"Left click : create/change mode room || create pipe/link pipe");
	mlx_string_put(mmkr->mlx, mmkr->win, 830, 1275, 0xFFA500, "Made by lgosse");
	if (mmkr->phase == 1)
		mlx_string_put(mmkr->mlx, mmkr->win, 405, 100, 0xFFFFFF,
			"Go to the next step");
	mlx_string_put(mmkr->mlx, mmkr->win, 800, 30, 0xFFFFFF,
		"To finish creation,");
	mlx_string_put(mmkr->mlx, mmkr->win, 800, 60, 0xFFFFFF,
		"press [ESC]");
	if (mmkr->phase == 1)
		mlx_string_put(mmkr->mlx, mmkr->win, 455, 150, 0xFFFFFF, "ROOM STEP");
	else if (mmkr->phase == 2)
		mlx_string_put(mmkr->mlx, mmkr->win, 455, 150, 0xFFFFFF, "PIPE STEP");
}

void		ft_handlegrid(t_mmkr *mmkr, int xc, int yc, int button)
{
	int		x;
	int		y;

	if (button == 1)
	{
		if (mmkr->tab[xc][yc] != 3)
			mmkr->tab[xc][yc]++;
		else
			mmkr->tab[xc][yc] = 1;
	}
	else
		mmkr->tab[xc][yc] = 0;
	ft_reinit_window(mmkr);
	y = 0;
	while (y < 39)
	{
		x = -1;
		while (++x < 39)
			if (mmkr->tab[y][x])
				ft_colorcase(mmkr, x, y, mmkr->tab[y][x]);
		y++;
	}
}
