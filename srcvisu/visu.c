/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 11:13:55 by lgosse            #+#    #+#             */
/*   Updated: 2016/05/13 18:59:18 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visu.h"

static t_list	*ft_initlstants(int nb_ants, t_list *map)
{
	t_list			*ants;
	t_list			*tmp;
	t_room			*start;
	int				i;

	i = nb_ants;
	ants = NULL;
	start = ft_getroomwid(map, 1);
	start->nb_ants = nb_ants;
	while (i > 0)
	{
		tmp = NULL;
		if (!(tmp = (t_list *)malloc(sizeof(t_list))))
			return (NULL);
		tmp->content = start;
		tmp->content_size = i;
		ft_lstadd(&ants, tmp);
		i--;
	}
	return (ants);
}

int				main(void)
{
	t_visu	*visu;

	if ((visu = (t_visu *)malloc(sizeof(t_visu))))
	{
		visu->map = ft_getleminmap(&visu->nb_ants);
		if (visu->map)
			if ((visu->ants = ft_initlstants(visu->nb_ants, visu->map))
				&& ft_initmlxvisu(visu))
			{
				mlx_loop_hook(visu->mlx, &ft_wait, visu);
				mlx_key_hook(visu->win, &ft_handlekeys, visu);
				mlx_put_image_to_window(visu->mlx, visu->win, visu->img, 0, 0);
				mlx_loop(visu->mlx);
			}
	}
	return (1);
}
