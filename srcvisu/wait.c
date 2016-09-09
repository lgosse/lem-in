/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 14:10:24 by lgosse            #+#    #+#             */
/*   Updated: 2016/05/13 12:21:53 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visu.h"

int		ft_wait(t_visu *visu)
{
	if (visu->action == 1)
	{
		visu->action = 1;
		mlx_clear_window(visu->mlx, visu->win);
		mlx_put_image_to_window(visu->mlx, visu->win, visu->img, 0, 0);
		ft_handleline(visu, NULL);
	}
	return (1);
}
