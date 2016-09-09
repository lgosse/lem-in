/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getinstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 15:43:21 by lgosse            #+#    #+#             */
/*   Updated: 2016/03/03 16:57:45 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_getflag(char *fmt, t_instr *instr, int *i)
{
	while (fmt[*i] != '\0' && (fmt[*i] == '#' || fmt[*i] == '0' ||
				fmt[*i] == '-' || fmt[*i] == '+' || fmt[*i] == ' '))
	{
		if (fmt[*i] == '#')
			instr->flag = instr->flag | HT;
		else if (fmt[*i] == '0')
			instr->flag = instr->flag | ZERO;
		else if (fmt[*i] == '-')
			instr->flag = instr->flag | MIN;
		else if (fmt[*i] == '+')
			instr->flag = instr->flag | PLUS;
		else if (fmt[*i] == ' ')
			instr->flag = instr->flag | SP;
		(*i)++;
	}
}

void	ft_getwidth(char *fmt, t_instr *instr, int *i, va_list ap)
{
	if (ft_isdigit(fmt[*i]) == 0)
	{
		if (fmt[*i] == '*')
		{
			instr->width = va_arg(ap, int);
			if (instr->width < 0)
			{
				instr->width = -instr->width;
				instr->flag = instr->flag | MIN;
			}
			(*i)++;
			ft_getwidth(fmt, instr, i, ap);
		}
		return ;
	}
	instr->width = ft_atoi(fmt + *i);
	while (ft_isdigit(fmt[*i]) == 1)
		(*i)++;
	ft_getwidth(fmt, instr, i, ap);
}

void	ft_getprec(char *fmt, t_instr *instr, int *i, va_list ap)
{
	if (fmt[*i] != '.')
		return ;
	instr->flag = instr->flag | PREC;
	(*i)++;
	if (ft_isdigit(fmt[*i]) == 0)
	{
		if (fmt[*i] == '*')
		{
			instr->precision = va_arg(ap, int);
			if (instr->precision < 0)
			{
				instr->precision = 0;
				instr->flag = instr->flag & NON_PREC;
			}
			(*i)++;
		}
		return ;
	}
	instr->precision = ft_atoi(fmt + *i);
	while (ft_isdigit(fmt[*i]) == 1)
		(*i)++;
	ft_getprec(fmt, instr, i, ap);
}

void	ft_getlm(char *fmt, t_instr *instr, int *i)
{
	while (ft_strchr("hljz", fmt[*i]) && fmt[*i] != '\0')
	{
		if (fmt[*i] == 'h' && fmt[*i + 1] != '\0' && fmt[*i + 1] == 'h')
			instr->lm = instr->lm | HH;
		else if (fmt[*i] == 'l' && fmt[*i + 1] != '\0' && fmt[*i + 1] == 'l')
			instr->lm = instr->lm | LL;
		else if (fmt[*i] == 'l')
			instr->lm = instr->lm | L;
		else if (fmt[*i] == 'h')
			instr->lm = instr->lm | H;
		else if (fmt[*i] == 'j')
			instr->lm = instr->lm | J;
		else if (fmt[*i] == 'z')
			instr->lm = instr->lm | Z;
		(*i)++;
	}
}

int		ft_getcs(char *fmt, t_instr *instr, int *i)
{
	if (fmt[*i] == 's' || fmt[*i] == 'S' || fmt[*i] == 'p' ||
			fmt[*i] == 'd' || fmt[*i] == 'D' || fmt[*i] == 'i' ||
			fmt[*i] == 'o' || fmt[*i] == 'O' || fmt[*i] == 'u' ||
			fmt[*i] == 'U' || fmt[*i] == 'x' || fmt[*i] == 'X' ||
			fmt[*i] == 'c' || fmt[*i] == 'C' || fmt[*i] == '%' ||
			fmt[*i] == 'b' || fmt[*i] == 'B' || fmt[*i] == 'T' ||
			fmt[*i] == '@')
	{
		instr->cs = fmt[*i];
		(*i)++;
		return (1);
	}
	return (0);
}
