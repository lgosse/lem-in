/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapmaker.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 14:28:46 by lgosse            #+#    #+#             */
/*   Updated: 2016/05/08 15:09:01 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mapmaker.h"

void	ft_inittab(t_mmkr *mmkr)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	mmkr->tab = (int **)malloc(sizeof(int*) * 40);
	mmkr->tab[39] = NULL;
	while (x < 39)
	{
		mmkr->tab[x] = (int *)malloc(sizeof(int) * 40);
		y = -1;
		while (++y < 39)
			mmkr->tab[x][y] = 0;
		x++;
	}
}

void	ft_pixel_put_to_image(t_mmkr *mmkr, int x, int y, int color)
{
	int			i;
	char		*data;

	i = 0;
	data = mmkr->data + y * mmkr->sline + x * (mmkr->bpp / 8);
	if (!mmkr->endian)
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

void	ft_initgrid(t_mmkr *mmkr)
{
	int		x;
	int		y;

	mmkr->img = mlx_new_image(mmkr->mlx, 1000, 1000);
	mmkr->data = mlx_get_data_addr(mmkr->img, &mmkr->bpp, &mmkr->sline,
		&mmkr->endian);
	y = 0;
	while (y <= 975)
	{
		x = 24;
		while (++x <= 975)
			ft_pixel_put_to_image(mmkr, x, y, 0xffffff);
		y += 25;
	}
	x = 25;
	while (x <= 975)
	{
		y = -1;
		while (++y <= 975)
			ft_pixel_put_to_image(mmkr, x, y, 0xffffff);
		x += 25;
	}
}

t_mmkr	*ft_initmmkr(void)
{
	t_mmkr	*mmkr;
	char	*title;

	title = NULL;
	if ((mmkr = (t_mmkr *)malloc(sizeof(t_mmkr))))
	{
		ft_inittitlenb_ants(mmkr, &title);
		if (mmkr->fd < 0)
		{
			free(mmkr);
			return (NULL);
		}
		mmkr->phase = 1;
		mmkr->mlx = mlx_init();
		mmkr->win = mlx_new_window(mmkr->mlx, 1000, 1300, title);
		free(title);
	}
	return (mmkr);
}

int		main(void)
{
	t_mmkr	*mmkr;

	if ((mmkr = ft_initmmkr()))
	{
		ft_initgrid(mmkr);
		ft_inithud(mmkr);
		ft_inittab(mmkr);
		mmkr->pos_crs = NULL;
		mmkr->pos1 = NULL;
		mmkr->pos2 = NULL;
		mmkr->pipes = NULL;
		ft_reinit_window(mmkr);
		mlx_mouse_hook(mmkr->win, &ft_handlemouse, mmkr);
		mlx_key_hook(mmkr->win, &ft_handlekeys, mmkr);
		mlx_hook(mmkr->win, 6, 1L << 6, &ft_motion_hook, mmkr);
		mlx_loop(mmkr->mlx);
	}
	return (1);
}
