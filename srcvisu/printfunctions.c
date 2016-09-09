/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfunctions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 12:21:57 by lgosse            #+#    #+#             */
/*   Updated: 2016/05/10 16:38:25 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visu.h"

void	ft_pixel_put_to_image(t_visu *visu, char *data, int color)
{
	int			i;

	i = 0;
	if (!visu->endian)
	{
		data[i++] = (char)color;
		data[i++] = (char)(color >> 8);
		data[i] = (char)(color >> 16);
	}
	else
	{
		data[i++] = (char)(color >> 16);
		data[i++] = (char)(color >> 8);
		data[i] = (char)color;
	}
}
