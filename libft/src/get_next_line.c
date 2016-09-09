/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getnextline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 17:40:27 by lgosse            #+#    #+#             */
/*   Updated: 2016/04/20 11:25:11 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				ft_treatnsave(char *buf, char **line, t_line *file)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	file->line = ft_strjoin_n_free(file->line, buf);
	i = ft_linelen(file->line);
	*line = (char *)malloc(sizeof(char ) * (i + 1));
	ft_memccpy(*line, file->line, '\n', ft_strlen(file->line));
	if ((*line)[i] == '\n' && file->line[i + 1] != '\0')
	{
		(*line)[i] = '\0';
		tmp = ft_strdup(&(file->line[i + 1]));
		free(file->line);
		file->line = tmp;
	}
	else
	{
		(*line)[i] = '\0';
		free(file->line);
		file->line = NULL;
	}
	free(buf);
	return (1);
}

static void		ft_fdlst_pback(t_line **alst, t_line *newelem)
{
	t_line *tmp;

	tmp = *alst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = newelem;
}

t_line			*ft_get_file(t_line **files, int fd)
{
	t_line			*search;
	t_line			*newelem;

	if (*files == NULL)
	{
		*files = (t_line *)malloc(sizeof(t_line));
		(*files)->next = NULL;
		(*files)->line = NULL;
		(*files)->fd = fd;
		return (*files);
	}
	search = *files;
	while (search)
	{
		if (search->fd == fd)
			return (search);
		else
			search = search->next;
	}
	newelem = (t_line *)malloc(sizeof(t_line));
	newelem->line = NULL;
	newelem->fd = fd;
	newelem->next = NULL;
	ft_fdlst_pback(files, newelem);
	return (newelem);
}

int				get_next_line(int const fd, char **line)
{
	static t_line	*files;
	t_line			*actual_file;
	char			*buf;
	int				ret;

	buf = ft_strnew(BUFF_SIZE);
	actual_file = ft_get_file(&files, fd);
	if (actual_file && actual_file->line && ft_strchr(actual_file->line, '\n'))
		return (ft_treatnsave(buf, line, actual_file));
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (ft_strchr(buf, '\n') == NULL)
			actual_file->line = ft_strjoin_n_free(actual_file->line, buf);
		if (ft_strchr(buf, '\n') != NULL)
			return (ft_treatnsave(buf, line, actual_file));
	}
	if (ret == -1)
		return (-1);
	if (actual_file->line)
		return (ft_treatnsave(buf, line, actual_file));
	free(buf);
	return (0);
}
