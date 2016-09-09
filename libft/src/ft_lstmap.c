/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 15:04:26 by lgosse            #+#    #+#             */
/*   Updated: 2015/11/30 15:31:07 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*pmap;
	t_list		*map;

	pmap = NULL;
	if ((pmap = f(lst)) == NULL)
		return (NULL);
	map = pmap;
	map->next = NULL;
	while (lst->next)
	{
		lst = lst->next;
		map->next = f(lst);
		if (map->next == NULL)
			return (NULL);
		map = map->next;
	}
	return (pmap);
}
