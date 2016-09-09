/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 18:10:33 by lgosse            #+#    #+#             */
/*   Updated: 2016/03/29 12:52:13 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 20
# include "libft.h"
# include <fcntl.h>

typedef struct			s_line
{
	char				*line;
	int					fd;
	struct s_line		*next;
}						t_line;

#endif
