/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemininit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 16:42:36 by lgosse            #+#    #+#             */
/*   Updated: 2016/05/14 11:11:19 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_room		*ft_initroom(char *line, int se)
{
	t_room		*room;
	int			len;
	static int	id;

	if ((room = (t_room *)malloc(sizeof(t_room))))
	{
		len = ft_wordlen(line, ' ');
		if (id == 0)
			id = 1;
		room->name = ft_strndup(line, len);
		room->ok = -1;
		room->id = se != -1 ? se : ++id;
		while (line[len] == ' ')
			len++;
		room->x = ft_atoi(line + len);
		while (ft_isdigit(line[len]))
			len++;
		while (line[len] == ' ')
			len++;
		room->y = ft_atoi(line + len);
		room->pipes = NULL;
		room->way = 0;
		room->nb_ants = 0;
	}
	return (room);
}

void		ft_createroom(char *line, t_list **map, int se)
{
	t_room		*room;
	t_list		*add;

	if ((room = ft_initroom(line, se)))
	{
		if ((add = (t_list *)malloc(sizeof(t_list))))
		{
			add->content = room;
			add->content_size = sizeof(room);
			ft_lstadd(map, add);
		}
	}
}

static int	ft_getrooms(t_list **file, t_list **map)
{
	if (ft_strequ((*file)->content, "##start") ||
		ft_strequ((*file)->content, "##end"))
		ft_treatcommands(file, map);
	else if (*(char *)(*file)->content == '#')
		;
	else if (ft_checkroomfmt((*file)->content) &&
		ft_checkname((*file)->content, *map))
		ft_createroom((*file)->content, map, -1);
	else
		return (2);
	return (1);
}

int			ft_treatline(t_list **file, t_list **map, int *nb_ants)
{
	static int	step;
	int			phase;

	phase = 0;
	if (step == 0 && ft_strisdigit((*file)->content))
	{
		step++;
		if ((*nb_ants = ft_atoi((*file)->content)) < 0)
			return (0);
	}
	else if (step == 1)
	{
		if (step == 1 && (step = ft_getrooms(file, map)) == 2)
			phase = 2;
	}
	else
		return (ft_getpipes(*file, map));
	if (phase == 2)
		return (2);
	return (1);
}

t_list		*ft_getleminmap(int *nb_ants)
{
	t_list	*file;
	t_list	*tmp;
	t_list	*map;

	map = NULL;
	file = ft_getinput();
	tmp = file;
	if (ft_initleminmap(&tmp, &map, nb_ants) == 0)
	{
		ft_lstdel(&file);
		return (NULL);
	}
	if (!ft_seemshillvalid(map) &&
		ft_printf("\nERROR : Missing informations\n%@", 2))
	{
		ft_lstdelbyfunc(&map, &ft_delhill);
		return (NULL);
	}
	ft_lstdel(&file);
	return (map);
}
