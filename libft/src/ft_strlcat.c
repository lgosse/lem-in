/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft__strlcat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:14:59 by lgosse            #+#    #+#             */
/*   Updated: 2015/12/12 19:01:42 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*str;
	size_t	toret;

	if (!(str = ft_memchr(dst, '\0', size)))
		return (size + ft_strlen(src));
	toret = (size_t)(str - dst) + ft_strlen(src);
	while ((size_t)(str - dst) < size - 1 && *src)
	{
		*str = *src;
		str++;
		src++;
	}
	*str = '\0';
	return (toret);
}
