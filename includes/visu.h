/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 11:14:34 by lgosse            #+#    #+#             */
/*   Updated: 2016/05/13 17:19:29 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H

# include "../libft/includes/libft.h"
# include "lem_in.h"
# include <mlx.h>

typedef struct	s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct	s_ant
{
	int			x1;
	int			y1;
	int			actx;
	int			acty;
	int			x2;
	int			y2;
	int			end;
	t_list		*ant;
	t_room		*room;
}				t_ant;

typedef struct	s_visu
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*data;
	void		*imgant;
	int			widthant;
	int			heightant;
	int			bpp;
	int			sline;
	int			endian;
	t_list		*map;
	t_list		*ants;
	int			action;
	int			nb_ants;
}				t_visu;

void			ft_placeant(t_visu *visu, t_pos *pos1, t_pos *pos2,
					t_list *ant);
void			ft_placeant2(t_visu *visu, t_pos *pos1, t_pos *pos2,
					t_list *ant);
void			ft_placeant3(t_visu *visu, t_pos *pos1, t_pos *pos2,
					t_list *ant);
void			ft_placeant4(t_visu *visu, t_pos *pos1, t_pos *pos2,
					t_list *ant);
t_room			*ft_getroomwcoords(t_visu *visu, int x, int y);
int				ft_wait(t_visu *visu);
void			ft_handleline(t_visu *visu, char *line);
void			ft_print_ants(t_visu *visu, t_list *ants);
int				ft_isanimend(t_list *ants);
void			ft_drawants(t_visu *visu);
int				ft_handlekeys(int keycode, t_visu *visu);
void			ft_setants(t_list **ants, t_room *room, t_list *ant);
int				ft_isanimend(t_list *ants);
void			ft_print_pipes(t_visu *visu);
int				ft_initrooms(t_visu *visu);
int				ft_initmlxvisu(t_visu *visu);
void			ft_initgrid(t_visu *visu);
void			ft_pixel_put_to_image(t_visu *visu, char *data, int color);

#endif
