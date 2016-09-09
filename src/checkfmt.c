/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfmt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 11:13:22 by lgosse            #+#    #+#             */
/*   Updated: 2016/04/26 13:27:22 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	ft_checkroomfmt2(char *line, int len)
{
	int i;

	i = 1;
	while (line[len + i] == ' ')
		i++;
	if (ft_isdigit(line[len + i]))
		while (line[len + i] != '\0' && ft_isdigit(line[len + i]))
			i++;
	else
		return (0);
	if (line[len + i] == ' ')
		while (line[len + i] == ' ')
			i++;
	if (ft_isdigit(line[len + i]))
		while (line[len + i] != '\0' && ft_isdigit(line[len + i]))
			i++;
	else
		return (0);
	if (line[len + i] != '\0')
		return (0);
	return (1);
}

int			ft_checkroomfmt(char *line)
{
	int len;

	len = ft_wordlen(line, ' ');
	if (*line != '#' && !ft_strnchr(line, '-', len) &&
		*line != 'L')
		return (ft_checkroomfmt2(line, len));
	return (0);
}

int			ft_checkpipefmt(char *line)
{
	if (*line != '-')
	{
		while (*line != '-' && *line != '\0')
			line++;
		if (*line == '-')
		{
			line++;
			if (*line != '\0')
				return (1);
		}
	}
	return (0);
}
