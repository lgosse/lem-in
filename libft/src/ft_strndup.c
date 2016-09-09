/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 15:38:58 by lgosse            #+#    #+#             */
/*   Updated: 2016/04/27 15:59:43 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strndup(char *str, int n)
{
	char	*str2;
	int		len;

	len = ft_strlen(str);
	len = len < n ? len : n;
	str2 = (char *)malloc(sizeof(char) * (len + 1));
	str2[len] = '\0';
	ft_strncpy(str2, str, len);
	return (str2);
}
