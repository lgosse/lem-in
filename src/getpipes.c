/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getpipes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 15:02:22 by lgosse            #+#    #+#             */
/*   Updated: 2016/04/27 15:48:04 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	ft_createpipethesequel(t_room *r1, t_room *r2)
{
	t_list	*add;

	add = NULL;
	if (r1 && r2)
	{
		if (ft_ispipevalid(r1, r2))
		{
			add = (t_list *)malloc(sizeof(t_list) * 1);
			add->content = r2;
			add->content_size = sizeof(r2);
			ft_lstadd(&r1->pipes, add);
			add = NULL;
			add = (t_list *)malloc(sizeof(t_list) * 1);
			add->content = r1;
			add->content_size = sizeof(r1);
			ft_lstadd(&r2->pipes, add);
			add = NULL;
		}
	}
	else
		return (-2);
	return (1);
}

static int	ft_createpipe(t_list *file, t_list **tmap)
{
	t_room	*r1;
	t_room	*r2;
	t_room	*tmp;
	t_list	*map;
	int		len;

	r1 = NULL;
	r2 = NULL;
	map = *tmap;
	len = ft_wordlen(file->content, '-');
	((char *)(file->content))[len] = '\0';
	while (map)
	{
		tmp = map->content;
		if (ft_strequ(tmp->name, file->content))
			r1 = tmp;
		if (ft_strequ(tmp->name, file->content + len + 1))
			r2 = tmp;
		map = map->next;
	}
	((char *)(file->content))[len] = '-';
	return (ft_createpipethesequel(r1, r2));
}

int			ft_getpipes(t_list *file, t_list **map)
{
	if (*(char *)file->content == '#')
		return (1);
	else if (ft_checkpipefmt(file->content))
		return (ft_createpipe(file, map));
	else
		return (-1);
}
