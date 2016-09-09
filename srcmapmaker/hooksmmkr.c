/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooksmmkr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 14:39:20 by lgosse            #+#    #+#             */
/*   Updated: 2016/05/07 17:23:06 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mapmaker.h"

int		ft_handlekeys(int keycode, t_mmkr *mmkr)
{
	if (keycode == 53)
	{
		ft_print_file(mmkr);
		exit(0);
	}
	return (1);
}

void	ft_change_phase(t_mmkr *mmkr)
{
	mmkr->phase = 2;
	ft_applyroomstoimg(mmkr);
	ft_reinit_window(mmkr);
}

int		ft_motion_hook(int x, int y, t_mmkr *mmkr)
{
	if (!mmkr->pos_crs)
		mmkr->pos_crs = (t_pos *)malloc(sizeof(t_pos));
	if (x > 0 && x < 1000 && y > 0 && y < 1300)
	{
		mmkr->pos_crs->x = x;
		mmkr->pos_crs->y = y;
		if (mmkr->pos1 && mmkr->pos_crs)
		{
			ft_reinit_window(mmkr);
			ft_draw_line(mmkr, mmkr->pos1, mmkr->pos_crs, 0xFF0000);
		}
		ft_print_pipes(mmkr);
	}
	return (1);
}

int		ft_handlemouse(int button, int x, int y, t_mmkr *mmkr)
{
	if (mmkr->phase == 1 && y > 300 && y < 1275 && x > 25 && x < 975)
	{
		y -= 300;
		x -= 25;
		ft_handlegrid(mmkr, y / 25, x / 25, button);
	}
	else if (x > 350 && x < 650 && y > 30 && y < 180 && mmkr->phase != 2)
		ft_change_phase(mmkr);
	else if (mmkr->phase == 2)
	{
		if (y > 300 && y < 1275 && x > 25 && x < 975)
		{
			y -= 300;
			x -= 25;
			ft_handlepipes(mmkr, x / 25, y / 25, button);
		}
	}
	return (1);
}
