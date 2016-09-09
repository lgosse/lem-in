/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 11:44:04 by lgosse            #+#    #+#             */
/*   Updated: 2016/04/09 14:29:53 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list		*ft_lstdup(t_list *src)
{
	t_list	*dst;

	dst = NULL;
	while (src)
	{
		ft_lstaddtail(&dst, ft_lstnew(src->content, src->content_size));
		src = src->next;
	}
	return (NULL);
}
