/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 17:52:21 by lgosse            #+#    #+#             */
/*   Updated: 2016/04/25 15:19:39 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static	int		ft_wrdlen(char const *s, char c)
{
	int i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

size_t			ft_count(char const *s, char c)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
			j++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (j);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	j;
	size_t	nb_len;

	tab = NULL;
	if (s != NULL)
		if ((tab = (char **)ft_memalloc(sizeof(char *) * (ft_count(s, c) + 1))))
		{
			i = 0;
			j = 0;
			while (j < ft_count(s, c))
			{
				while (s[i] == c && s[i])
					i++;
				nb_len = ft_wrdlen(s + i, c);
				tab[j] = ft_strsub(s, i, nb_len);
				i += nb_len;
				j++;
			}
			tab[j] = NULL;
		}
	return (tab);
}
