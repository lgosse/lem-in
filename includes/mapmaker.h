/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapmaker.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 14:29:16 by lgosse            #+#    #+#             */
/*   Updated: 2016/05/09 15:04:56 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPMAKER_H
# define MAPMAKER_H

# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"

typedef struct	s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct	s_seg
{
	int			x1;
	int			y1;
	int			x2;
	int			y2;
}				t_seg;

typedef struct	s_mmkr
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*data;
	void		*hud;
	void		*datahud;
	int			bpp;
	int			sline;
	int			endian;
	int			bpp2;
	int			sline2;
	int			endian2;
	int			fd;
	int			**tab;
	int			phase;
	t_pos		*pos_crs;
	t_pos		*pos1;
	t_pos		*pos2;
	t_list		*pipes;
	int			nb_ants;
}				t_mmkr;

void			ft_draw_line_to_img(t_mmkr *mmkr, t_pos *pos1, t_pos *pos2,
		int color);
void			ft_inittitlenb_ants(t_mmkr *mmkr, char **title);
void			ft_print_file(t_mmkr *mmkr);
void			ft_print_pipes(t_mmkr *mmkr);
void			ft_createpipe(t_mmkr *mmkr);
void			ft_draw_line(t_mmkr *mmkr, t_pos *pos1, t_pos *pos2, int color);
void			ft_pixel_put_to_image(t_mmkr *mmkr, int x, int y, int color);
int				ft_handlekeys(int keycode, t_mmkr *mmkr);
int				ft_handlemouse(int button, int x, int y, t_mmkr *mmkr);
int				ft_motion_hook(int x, int y, t_mmkr *mmkr);
void			ft_handlegrid(t_mmkr *mmkr, int x, int y, int button);
void			ft_inithud(t_mmkr *mmkr);
void			ft_colorcase(t_mmkr *mmkr, int x, int y, int color);
void			ft_reinit_window(t_mmkr *mmkr);
void			ft_applyroomstoimg(t_mmkr *mmkr);
void			ft_handlepipes(t_mmkr *mmkr, int x, int y, int button);

#endif
