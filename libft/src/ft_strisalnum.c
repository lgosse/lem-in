/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisalnum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 13:52:13 by lgosse            #+#    #+#             */
/*   Updated: 2016/03/07 13:55:08 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strisalnum(char *str)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
		if (!ft_isalpha(str[i]) && !ft_isdigit(str[i]))
			return (0);
	return (1);
}
