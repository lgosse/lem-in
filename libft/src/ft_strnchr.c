/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 13:01:30 by lgosse            #+#    #+#             */
/*   Updated: 2016/04/23 16:41:15 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnchr(const char *s, int c, int n)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (str[i] != c && str[i] != '\0' && i < n)
		i++;
	if ((str[i] == 0 || i == n) && c != 0)
		return (NULL);
	return (str + i);
}
