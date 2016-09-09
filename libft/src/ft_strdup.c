/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 14:43:12 by lgosse            #+#    #+#             */
/*   Updated: 2015/12/11 13:53:49 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	char *dest;

	dest = NULL;
	dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (dest != NULL)
		ft_strcpy(dest, s1);
	return (dest);
}
