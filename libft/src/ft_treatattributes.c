/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treatattributes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 13:51:00 by lgosse            #+#    #+#             */
/*   Updated: 2016/03/04 10:37:19 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_write_seq(t_print *print, char *seq)
{
	if (ft_isdigit(print->res[print->i - 1]))
	{
		if (print->i % 32 == 0)
			print->res = ft_realloc(print->res, print->i, print->sz++ * 32);
		print->res[print->i++] = ';';
	}
	print->res[print->i++] = seq[0];
	print->res[print->i++] = seq[1];
}

static void	ft_writecolor(t_instr *instr, t_print *print)
{
	if (print->i % 32 == 0 || print->i + 1 % 32 == 0)
		print->res = ft_realloc(print->res, print->i, print->sz++ * 32);
	if (instr->attributes & DARK)
		ft_write_seq(print, "30");
	else if (instr->attributes & RED)
		ft_write_seq(print, "31");
	else if (instr->attributes & GREEN)
		ft_write_seq(print, "32");
	else if (instr->attributes & YELLOW)
		ft_write_seq(print, "33");
	else if (instr->attributes & BLUE)
		ft_write_seq(print, "34");
	else if (instr->attributes & MAGENTA)
		ft_write_seq(print, "35");
	else if (instr->attributes & CYAN)
		ft_write_seq(print, "36");
}

static void	ft_writebackground(t_instr *instr, t_print *print)
{
	if (print->i % 32 == 0 || print->i + 1 % 32 == 0)
		print->res = ft_realloc(print->res, print->i, print->sz++ * 32);
	else if (instr->attributes & (DARK << 8))
		ft_write_seq(print, "40");
	else if (instr->attributes & (RED << 8))
		ft_write_seq(print, "41");
	else if (instr->attributes & (GREEN << 8))
		ft_write_seq(print, "42");
	else if (instr->attributes & (YELLOW << 8))
		ft_write_seq(print, "43");
	else if (instr->attributes & (BLUE << 8))
		ft_write_seq(print, "44");
	else if (instr->attributes & (MAGENTA << 8))
		ft_write_seq(print, "45");
	else if (instr->attributes & (CYAN << 8))
		ft_write_seq(print, "46");
}

static void	ft_writetypo(t_instr *instr, t_print *print)
{
	if (print->i % 32 == 0 || print->i + 1 % 32 == 0)
		print->res = ft_realloc(print->res, print->i, print->sz++ * 32);
	if (instr->attributes & BOLD)
		ft_write_seq(print, "1;");
	if (instr->attributes & ITALIC)
		ft_write_seq(print, "3;");
	if (instr->attributes & UNDERLINE)
		ft_write_seq(print, "4;");
	if (instr->attributes & ENCIRCLED)
		ft_write_seq(print, "52");
	if (instr->attributes & FRAMED)
		ft_write_seq(print, "51");
	if (instr->attributes & OVERLINED)
		ft_write_seq(print, "53");
}

void		ft_treatattributes(t_instr *instr, t_print *print)
{
	char	*escape_seq;
	int		i;

	i = -1;
	escape_seq = ft_strdup("\033[");
	while (escape_seq[++i] != '\0')
	{
		if (print->i % 32 == 0)
			print->res = ft_realloc(print->res, print->i, print->sz++ * 32);
		print->res[print->i++] = escape_seq[i];
	}
	if (instr->attributes & COLOR)
		ft_writecolor(instr, print);
	if (instr->attributes & BACKGROUND)
		ft_writebackground(instr, print);
	if (instr->attributes & TYPO)
		ft_writetypo(instr, print);
	if (print->i % 32 == 0)
		print->res = ft_realloc(print->res, print->i, print->sz++ * 32);
	print->res[print->i++] = 'm';
	free(escape_seq);
}
