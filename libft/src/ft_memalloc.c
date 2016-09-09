/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:38:59 by lgosse            #+#    #+#             */
/*   Updated: 2015/12/08 16:53:24 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*ptr;

	ptr = NULL;
	if (size > 0)
		if ((ptr = (void *)malloc(size)))
			ft_bzero(ptr, size);
	return (ptr);
}
