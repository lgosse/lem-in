/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:54:28 by lgosse            #+#    #+#             */
/*   Updated: 2015/12/12 15:29:53 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strncmp(char const *s1, char const *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (0);
	if (*s1 != '\0' && *s2 != '\0')
	{
		while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i != n)
			i++;
		if (i == n)
			return (0);
	}
	return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
}
