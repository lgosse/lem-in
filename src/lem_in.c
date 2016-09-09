/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 10:44:20 by lgosse            #+#    #+#             */
/*   Updated: 2016/05/14 11:15:37 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		main(int ac, char **av)
{
	t_list	*map;
	int		nb_ants;
	t_parse *parse;

	map = ft_getleminmap(&nb_ants);
	if (map)
	{
		parse = ft_parse(ac, av, "cn");
		ft_initpond(map);
		if (ft_ismapvalid(map) == 2)
		{
			ft_printf("\n");
			ft_invaliduselessways(map);
			ft_initants(nb_ants, map, parse);
			ft_free_parse(parse);
			ft_lstdelbyfunc(&map, &ft_delhill);
		}
		else
		{
			ft_printf("\nERROR : No ways to the end\n%@", 2);
			return (0);
		}
	}
	return (1);
}
