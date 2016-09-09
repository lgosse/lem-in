/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_n_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 11:17:16 by lgosse            #+#    #+#             */
/*   Updated: 2016/01/25 16:12:48 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strjoin_n_free(char *s1, char *s2)
{
	char *str;

	str = ft_strjoin(s1, s2);
	if (s1)
		free(s1);
	return (str);
}
