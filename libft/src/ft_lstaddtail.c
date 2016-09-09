/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddtail.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 11:20:07 by lgosse            #+#    #+#             */
/*   Updated: 2016/04/08 13:58:44 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		ft_lstaddtail(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (alst && *alst)
	{
		tmp = *alst;
		while (tmp && tmp->next)
			tmp = tmp->next;
		if (tmp)
			tmp->next = new;
	}
	else if (alst)
		*alst = new;
}
