/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatcommands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 14:07:39 by lgosse            #+#    #+#             */
/*   Updated: 2016/04/27 18:09:23 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		ft_treatcommands(t_list **file, t_list **map)
{
	int		se;

	se = -1;
	if (ft_strequ((*file)->content, "##start"))
		se = 1;
	else if (ft_strequ((*file)->content, "##end"))
		se = 0;
	while (*file && !ft_checkroomfmt((*file)->content))
	{
		ft_printf("%s\n", (*file)->content);
		*file = (*file)->next;
	}
	if (*file && ft_checkname((*file)->content, *map))
		ft_createroom((*file)->content, map, se);
}

int			ft_checkname(char *name, t_list *map)
{
	t_room	*tmp;

	while (map)
	{
		tmp = map->content;
		if (!ft_strcmp(name, tmp->name))
			return (0);
		map = map->next;
	}
	return (1);
}

void		ft_delhill(void *content)
{
	t_room	*room;

	if (content)
	{
		room = content;
		ft_lstdelbyfunc(&room->pipes, NULL);
		free(room->name);
		free(content);
	}
}

int			ft_printmap(t_list *map)
{
	t_list		*pipes;

	ft_printf("\nMAP : \n\n");
	while (map)
	{
		pipes = ((t_room *)map->content)->pipes;
		ft_printf("Name : %s\n", ((t_room *)map->content)->name);
		ft_printf("ID : %d\n", ((t_room *)map->content)->id);
		ft_printf("pipes : ");
		while (pipes)
		{
			ft_printf("-%s-", ((t_room *)(pipes->content))->name);
			pipes = pipes->next;
		}
		ft_printf("\nbalance : %d\n", ((t_room *)map->content)->ok);
		ft_printf("way : %d\n", ((t_room *)map->content)->way);
		map = map->next;
		ft_printf("\n");
	}
	return (1);
}
