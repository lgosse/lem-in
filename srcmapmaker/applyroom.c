/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   applyroom.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 16:20:28 by lgosse            #+#    #+#             */
/*   Updated: 2016/05/04 16:27:30 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mapmaker.h"

void	ft_colorcase3(t_mmkr *mmkr, int x, int y, int color)
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
			ft_pixel_put_to_image(mmkr, x, y - 300, color);
			y++;
		}
		x++;
	}
}

void	ft_applyroomstoimg(t_mmkr *mmkr)
{
	int		x;
	int		y;

	y = 0;
	while (y < 39)
	{
		x = -1;
		while (++x < 39)
			if (mmkr->tab[y][x])
				ft_colorcase3(mmkr, x, y, mmkr->tab[y][x]);
		y++;
	}
}
