/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 12:56:46 by lgosse            #+#    #+#             */
/*   Updated: 2016/02/01 17:50:45 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../includes/libft.h"

void		*ft_realloc(void *ptr, int sizeofptr, int size)
{
	void	*newptr;

	newptr = (void *)malloc(sizeofptr + size);
	ft_memcpy(newptr, ptr, sizeofptr);
	free(ptr);
	return (newptr);
}
