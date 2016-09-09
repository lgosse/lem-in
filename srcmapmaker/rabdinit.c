/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rabdinit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 11:45:31 by lgosse            #+#    #+#             */
/*   Updated: 2016/05/06 17:39:04 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mapmaker.h"

void		ft_pixel_put_to_image2(t_mmkr *mmkr, int x, int y, int color)
{
	int			i;
	char		*data;

	i = 0;
	data = mmkr->datahud + y * mmkr->sline2 + x * (mmkr->bpp2 / 8);
	if (!mmkr->endian2)
	{
		data[i++] = (char)color;
		data[i++] = (char)(color >> 8);
		data[i] = (char)(color >> 16);
	}
	else
	{
		data[i++] = (char)(color >> 16);
		data[i++] = (char)(color >> 8);
		data[i] = (char)color;
	}
}

void		ft_colorcaseimg(t_mmkr *mmkr, int x, int y, int color)
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
	tmp = y;
	x2 = x + 25;
	y2 = y + 25;
	while (x < x2)
	{
		y = tmp;
		while (y < y2)
		{
			ft_pixel_put_to_image2(mmkr, x, y, color);
			y++;
		}
		x++;
	}
}

void		ft_buttonnextstep(t_mmkr *mmkr, int startx, int starty, int color)
{
	int		x;
	int		y;
	int		x2;
	int		y2;

	x = startx;
	y = starty;
	x2 = x + 300;
	y2 = y + 150;
	while (x <= x2)
	{
		y = starty;
		while (y <= y2)
		{
			if (x == startx || x == x2 || y == starty || y == y2)
				ft_pixel_put_to_image2(mmkr, x, y, color);
			y++;
		}
		x++;
	}
}

void		ft_inithud(t_mmkr *mmkr)
{
	mmkr->hud = mlx_new_image(mmkr->mlx, 1000, 300);
	mmkr->datahud = mlx_get_data_addr(mmkr->hud, &mmkr->bpp2, &mmkr->sline2,
		&mmkr->endian2);
	ft_colorcaseimg(mmkr, 25, 25, 1);
	ft_colorcaseimg(mmkr, 25, 75, 2);
	ft_colorcaseimg(mmkr, 25, 125, 3);
	ft_buttonnextstep(mmkr, 350, 30, 0xFFFFFF);
}
