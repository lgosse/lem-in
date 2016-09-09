/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 17:42:56 by lgosse            #+#    #+#             */
/*   Updated: 2016/05/09 18:15:40 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mapmaker.h"

void	ft_inittitlenb_ants(t_mmkr *mmkr, char **title)
{
	ft_printf("Enter the number of ants you want :\n");
	get_next_line(0, title);
	mmkr->nb_ants = ft_atoi(*title);
	ft_memdel((void **)title);
	while (ft_strlen(*title) < 1)
	{
		ft_printf("Enter the name of the map you want to create :\n");
		if (*title)
			free(*title);
		get_next_line(0, title);
	}
	mmkr->fd = open(*title, O_RDWR | O_EXCL | O_CREAT, S_IRWXU);
}

void	ft_clean_all(t_mmkr *mmkr)
{
	mlx_destroy_image(mmkr->mlx, mmkr->img);
	mlx_destroy_image(mmkr->mlx, mmkr->hud);
	mlx_destroy_window(mmkr->mlx, mmkr->win);
	mmkr->pos_crs ? free(mmkr->pos_crs) : 0;
	mmkr->pos1 ? free(mmkr->pos1) : 0;
	mmkr->pos2 ? free(mmkr->pos2) : 0;
	ft_lstdel(&mmkr->pipes);
	ft_tabdel((void **)mmkr->tab);
}

void	ft_finishprint(t_mmkr *mmkr)
{
	t_list	*tmp;
	t_seg	*seg;

	seg = NULL;
	tmp = mmkr->pipes;
	while (tmp)
	{
		seg = tmp->content;
		ft_printf("x%dy%d-x%dy%d\n%@", (seg->x1 - 38) / 25,
			(seg->y1 - 312) / 25,
			(seg->x2 - 38) / 25, (seg->y2 - 312) / 25,
			mmkr->fd);
		tmp = tmp->next;
	}
	close(mmkr->fd);
	ft_clean_all(mmkr);
}

void	ft_print_file(t_mmkr *mmkr)
{
	int		x;
	int		y;

	y = -1;
	ft_printf("%d\n#rooms step\n%@", mmkr->nb_ants, mmkr->fd);
	while (++y < 39)
	{
		x = -1;
		while (++x < 39)
		{
			if (mmkr->tab[y][x] == 1)
				ft_printf("x%dy%d %d %d\n%@", x, y, x, y, mmkr->fd);
			else if (mmkr->tab[y][x] == 2)
				ft_printf("##start\nx%dy%d %d %d\n%@", x, y, x, y, mmkr->fd);
			else if (mmkr->tab[y][x] == 3)
				ft_printf("##end\nx%dy%d %d %d\n%@", x, y, x, y, mmkr->fd);
		}
	}
	ft_printf("#pipes step\n%@", mmkr->fd);
	ft_finishprint(mmkr);
}
