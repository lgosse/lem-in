/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabstrdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 16:25:50 by lgosse            #+#    #+#             */
/*   Updated: 2016/03/13 13:39:10 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		**ft_tabstrdup(char **tab)
{
	int		i;
	char	**dup;

	i = 0;
	dup = NULL;
	while (tab[i])
		i++;
	if ((dup = (char **)malloc(sizeof(char *) * (i + 1))))
	{
		dup[i] = NULL;
		while (i--)
			dup[i] = ft_strdup(tab[i]);
	}
	return (dup);
}
