/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 16:10:21 by lgosse            #+#    #+#             */
/*   Updated: 2016/05/13 18:59:34 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visu.h"

static void	ft_get_straight_outta_shit(t_visu *visu)
{
	mlx_destroy_image(visu->mlx, visu->img);
	mlx_destroy_image(visu->mlx, visu->imgant);
	mlx_destroy_window(visu->mlx, visu->win);
	ft_lstdelbyfunc(&visu->map, &ft_delhill);
	ft_lstdelbyfunc(&visu->ants, NULL);
	free(visu);
	exit(0);
}

int			ft_handlekeys(int keycode, t_visu *visu)
{
	if (keycode == 53)
		ft_get_straight_outta_shit(visu);
	else if (visu->action == -1)
	{
		visu->action = 1;
		ft_drawants(visu);
	}
	return (1);
}
