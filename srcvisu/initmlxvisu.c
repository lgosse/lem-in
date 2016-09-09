/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initmlxvisu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 11:31:08 by lgosse            #+#    #+#             */
/*   Updated: 2016/05/13 17:18:37 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visu.h"

static int		ft_drawant(t_visu *visu)
{
	visu->widthant = 48;
	visu->heightant = 32;
	if ((visu->imgant = mlx_xpm_file_to_image(visu->mlx, "./skinant/ant.xpm",
		&visu->widthant, &visu->heightant)))
		return (1);
	return (0);
}

int				ft_initmlxvisu(t_visu *visu)
{
	if ((visu->mlx = mlx_init()) &&
		(visu->win = mlx_new_window(visu->mlx, 1000, 1000, "LEM-IN")) &&
		(visu->img = mlx_new_image(visu->mlx, 1000, 1000)) &&
		(visu->data = mlx_get_data_addr(visu->img, &visu->bpp, &visu->sline,
			&visu->endian)))
	{
		ft_drawant(visu);
		visu->action = -1;
		if (!ft_initrooms(visu))
			return (0);
		ft_print_pipes(visu);
		return (1);
	}
	return (0);
}
