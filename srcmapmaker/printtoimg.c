/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printtoimg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 14:59:56 by lgosse            #+#    #+#             */
/*   Updated: 2016/05/09 15:16:08 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mapmaker.h"

void	ft_put_line4(t_mmkr *mmkr, t_pos *pos1, t_pos *pos2, int color)
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
			ft_pixel_put_to_image(mmkr, x, y - 300, color);
		x++;
	}
}

void	ft_put_line3(t_mmkr *mmkr, t_pos *pos1, t_pos *pos2, int color)
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
			ft_pixel_put_to_image(mmkr, x, y - 300, color);
		y++;
	}
}

void	ft_draw_line_to_img(t_mmkr *mmkr, t_pos *pos1, t_pos *pos2, int color)
{
	if (ft_abs(pos2->x - pos1->x) > ft_abs(pos2->y - pos1->y))
	{
		if (pos2->x - pos1->x > 0)
			ft_put_line4(mmkr, pos1, pos2, color);
		else
			ft_put_line4(mmkr, pos2, pos1, color);
	}
	else if (pos2->y - pos1->y > 0)
		ft_put_line3(mmkr, pos1, pos2, color);
	else
		ft_put_line3(mmkr, pos2, pos1, color);
}
