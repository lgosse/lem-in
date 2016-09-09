/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:46:27 by lgosse            #+#    #+#             */
/*   Updated: 2015/12/08 18:20:01 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strtrim(char const *s)
{
	int		start;
	int		end;

	if (s == NULL)
		return (NULL);
	start = 0;
	end = ft_strlen(s) - 1;
	if (s != NULL)
	{
		while ((s[start] == ' ' || s[start] == '\n' || s[start] == '\t') &&
				s[start] != '\0')
			start++;
		while ((s[end] == ' ' || s[end] == '\n' || s[end] == '\t') && end != 0
				&& end > start)
			end--;
	}
	return (ft_strsub(s, start, end - start + 1));
}
