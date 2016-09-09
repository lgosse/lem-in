/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelfirst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 16:22:11 by lgosse            #+#    #+#             */
/*   Updated: 2016/04/20 16:27:29 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		ft_lstdelfirst(t_list **alst)
{
	t_list	*tmp;

	if (*alst && (*alst)->content)
	{
		tmp = (*alst)->next;
		free((*alst)->content);
		free(*alst);
		*alst = tmp;
	}
}
