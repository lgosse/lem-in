/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 12:45:19 by lgosse            #+#    #+#             */
/*   Updated: 2016/04/08 13:57:02 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new_list;

	new_list = (t_list *)malloc(sizeof(t_list));
	if (new_list != NULL)
	{
		if (content_size == 0 || content == NULL)
		{
			new_list->content = NULL;
			new_list->content_size = 0;
		}
		else
		{
			new_list->content = (void *)malloc(content_size);
			if (new_list->content != NULL)
			{
				ft_memcpy(new_list->content, content, content_size);
				new_list->content_size = content_size;
			}
		}
		new_list->next = NULL;
	}
	return (new_list);
}
