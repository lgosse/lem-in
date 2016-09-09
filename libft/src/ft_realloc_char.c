/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 11:39:01 by lgosse            #+#    #+#             */
/*   Updated: 2016/01/02 12:18:59 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_realloc_char(char *ptr, size_t size)
{
	char *newptr;

	newptr = (char *)malloc(sizeof(char) * size + 1);
	if (ptr != NULL)
	{
		ft_strcpy(newptr, ptr);
		free(ptr);
	}
	return (newptr);
}
