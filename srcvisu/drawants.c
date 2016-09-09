/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:11:50 by lgosse            #+#    #+#             */
/*   Updated: 2016/07/07 16:27:51 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visu.h"

t_room			*ft_getroomwcoords(t_visu *visu, int x, int y)
{
	t_list	*tmp;
	t_room	*room;

	tmp = visu->map;
	room = NULL;
	while (tmp)
	{
		room = tmp->content;
		if (room->x == x && room->y == y)
			return (room);
		tmp = tmp->next;
	}
	return (NULL);
}

static t_room	*ft_getmvroom(t_visu *visu, char *line)
{
	t_list	*tmp;
	t_room	*room;
	int		len;

	tmp = visu->map;
	len = ft_wordlen(line, ' ');
	line[len] = '\0';
	while (tmp)
	{
		room = tmp->content;
		if (!ft_strncmp(room->name, line, ft_strlen(room->name)))
		{
			line[len] = '-';
			return (room);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

static t_list	*ft_getmvant(t_visu *visu, char *line)
{
	t_list	*ants;
	int		id;

	id = ft_atoi(line);
	ants = visu->ants;
	while (ants)
	{
		if (ants->content_size == (unsigned long)id)
			return (ants);
		ants = ants->next;
	}
	return (NULL);
}

void			ft_handleline(t_visu *visu, char *line)
{
	t_list			*ant;
	static t_list	*ants;
	t_room			*room;

	ant = NULL;
	while (line && *line)
	{
		if (*line == 'L')
			line++;
		room = ft_getmvroom(visu, line + ft_wordlen(line, '-') + 1);
		ant = ft_getmvant(visu, line);
		ft_setants(&ants, room, ant);
		while (*line != 'L' && *line != '\0')
			line++;
	}
	ft_print_ants(visu, ants);
	if (ft_isanimend(ants))
	{
		ft_lstdel(&ants);
		ants = NULL;
	}
}

void			ft_drawants(t_visu *visu)
{
	char	*line;

	line = NULL;
	if (get_next_line(0, &line))
	{
		ft_printf("%s\n", line);
		ft_handleline(visu, line);
		ft_memdel((void **)&line);
	}
}
