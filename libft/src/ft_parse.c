/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 11:06:12 by lgosse            #+#    #+#             */
/*   Updated: 2016/04/27 16:25:35 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstdel(t_list **list)
{
	if (*list)
	{
		ft_lstdel(&((*list)->next));
		if ((*list)->content)
		{
			free((*list)->content);
			(*list)->content = NULL;
		}
		free(*list);
	}
}

void	ft_free_parse(t_parse *parse)
{
	ft_lstdel(&(parse->args));
	free(parse);
}

void	ft_getargs(char **av, char *opt, t_parse *parse)
{
	int i;

	i = 0;
	while (av[i] && av[i][0] == '-' && ft_strchr(opt, av[i][1]))
		i++;
	while (av[i])
	{
		ft_lstaddtail(&(parse->args), ft_lstnew(av[i], ft_strlen(av[i]) + 1));
		i++;
	}
}

char	ft_getopt(char **av, char *opt, t_parse *parse)
{
	char	*ret;
	int		i;
	int		j;

	i = 1;
	(void)parse;
	while (av[i] && av[i][0] == '-' && ft_strchr(opt, av[i][1]))
	{
		j = 1;
		while (av[i][j] && (ret = ft_strchr(opt, av[i][j])))
		{
			parse->opt |= ft_pow(2, (ret - opt));
			j++;
		}
		if (ret == NULL)
			return (av[i][j]);
		i++;
	}
	if (av[i] && av[i][0] == '-' && av[i][1] != '-')
		return (av[i][1]);
	return (0);
}

t_parse	*ft_parse(int ac, char **av, char *opt)
{
	t_parse	*parse;
	char	ret;

	parse = NULL;
	parse = (t_parse *)malloc(sizeof(t_parse) * 1);
	if (parse)
	{
		parse->args = NULL;
		parse->opt = 0;
		parse->nb_arg = ac - 1;
		if ((ret = ft_getopt(av, opt, parse)))
		{
			ft_printf("%s: illegal option -- %c\nusage: %s [-%s] [args...]\n",
				av[0], ret, av[0], opt);
			free(parse);
			return (NULL);
		}
		ft_getargs(av + 1, opt, parse);
	}
	return (parse);
}
