/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getattributes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 10:48:54 by lgosse            #+#    #+#             */
/*   Updated: 2016/03/29 12:43:45 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_getcolor(char *fmt, t_instr *instr, int *i)
{
	if (ft_strchr("drgybmc", fmt[*i]))
	{
		instr->attributes = instr->attributes | COLOR;
		if (fmt[*i] == 'd')
			instr->attributes = instr->attributes | DARK;
		else if (fmt[*i] == 'r')
			instr->attributes = instr->attributes | RED;
		else if (fmt[*i] == 'g')
			instr->attributes = instr->attributes | GREEN;
		else if (fmt[*i] == 'y')
			instr->attributes = instr->attributes | YELLOW;
		else if (fmt[*i] == 'b')
			instr->attributes = instr->attributes | BLUE;
		else if (fmt[(*i)] == 'm')
			instr->attributes = instr->attributes | MAGENTA;
		else if (fmt[(*i)] == 'c')
			instr->attributes = instr->attributes | CYAN;
		(*i)++;
		while (fmt[*i] == ',' || fmt[*i] == ' ')
			(*i)++;
	}
}

static void		ft_getbackground(char *fmt, t_instr *instr, int *i)
{
	if (ft_strchr("drgybmc", fmt[*i]))
	{
		instr->attributes = instr->attributes | BACKGROUND;
		if (fmt[*i] == 'd')
			instr->attributes = instr->attributes | (DARK << 8);
		else if (fmt[*i] == 'r')
			instr->attributes = instr->attributes | (RED << 8);
		else if (fmt[*i] == 'g')
			instr->attributes = instr->attributes | (GREEN << 8);
		else if (fmt[*i] == 'y')
			instr->attributes = instr->attributes | (YELLOW << 8);
		else if (fmt[*i] == 'b')
			instr->attributes = instr->attributes | (BLUE << 8);
		else if (fmt[*i] == 'm')
			instr->attributes = instr->attributes | (MAGENTA << 8);
		else if (fmt[*i] == 'c')
			instr->attributes = instr->attributes | (CYAN << 8);
		(*i)++;
		while (fmt[*i] == ',' || fmt[*i] == ' ')
			(*i)++;
	}
}

static void		ft_gettypo(char *fmt, t_instr *instr, int *i)
{
	if (ft_strchr("BIUEFO", fmt[*i]))
	{
		instr->attributes = instr->attributes | TYPO;
		if (fmt[*i] == 'B')
			instr->attributes = instr->attributes | BOLD;
		if (fmt[*i] == 'I')
			instr->attributes = instr->attributes | ITALIC;
		if (fmt[*i] == 'U')
			instr->attributes = instr->attributes | UNDERLINE;
		if (fmt[*i] == 'E')
			instr->attributes = instr->attributes | ENCIRCLED;
		if (fmt[*i] == 'F')
			instr->attributes = instr->attributes | FRAMED;
		if (fmt[*i] == 'O')
			instr->attributes = instr->attributes | OVERLINED;
		(*i)++;
		while (fmt[*i] == ',' || fmt[*i] == ' ')
			(*i)++;
	}
}

void			ft_getattributes(char *fmt, t_instr *instr, int *i)
{
	if (fmt[*i] == '[')
	{
		(*i)++;
		if (fmt[*i] == '0')
		{
			(*i)++;
			instr->attributes = instr->attributes | RESET_ATTRIBUTES;
		}
		while (fmt[*i] != '\0' && fmt[*i] != ']')
		{
			ft_getcolor(fmt, instr, i);
			if (fmt[*i] == '\\')
			{
				(*i)++;
				ft_getbackground(fmt, instr, i);
			}
			ft_gettypo(fmt, instr, i);
		}
		if (fmt[*i] == ']')
			(*i)++;
		instr->attributes = instr->attributes | 1;
	}
}
