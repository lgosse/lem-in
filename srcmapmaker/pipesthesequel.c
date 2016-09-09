/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipesthesequel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 16:16:36 by lgosse            #+#    #+#             */
/*   Updated: 2016/05/06 16:31:19 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mapmaker.h"

void	ft_createpipe(t_mmkr *mmkr)
{
	t_seg	*seg;
	t_list	*tmp;

	seg = (t_seg *)malloc(sizeof(t_seg));
	seg->x1 = mmkr->pos1->x;
	seg->y1 = mmkr->pos1->y;
	seg->x2 = mmkr->pos2->x;
	seg->y2 = mmkr->pos2->y;
	ft_memdel((void **)&mmkr->pos1);
	ft_memdel((void **)&mmkr->pos2);
	tmp = (t_list *)malloc(sizeof(t_list));
	tmp->content = seg;
	ft_lstadd(&mmkr->pipes, tmp);
}
