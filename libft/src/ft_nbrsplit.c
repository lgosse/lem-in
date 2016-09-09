/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 16:35:18 by lgosse            #+#    #+#             */
/*   Updated: 2016/04/09 13:49:52 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	ft_countnumbers(char *str)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && !ft_isdigit(str[i]))
			i++;
		if (ft_isdigit(str[i]))
			nb++;
		while (str[i] != '\0' && !ft_iswhitespace(str[i]))
			i++;
		while (ft_isdigit(str[i]))
			i++;
	}
	return (nb);
}

void		ft_nbrsplit(t_list **alst, char *str)
{
	int		*map;
	int		i;
	int		j;
	int		size;

	map = NULL;
	i = 0;
	j = -1;
	size = ft_countnumbers(str);
	if (str != NULL)
	{
		if ((map = (int *)malloc(sizeof(int) * ft_countnumbers(str))))
			while (++j < size)
			{
				while (!ft_isdigit(str[i]))
					i++;
				map[j] = ft_atoi(str + i);
				while (str[i] != '\0' && !ft_iswhitespace(str[i]))
					i++;
				while (ft_isdigit(str[i]))
					i++;
			}
		ft_lstaddtail(alst, ft_lstnew(map, size * sizeof(int)));
		free(map);
	}
}
