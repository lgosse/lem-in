/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treatstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 12:42:15 by lgosse            #+#    #+#             */
/*   Updated: 2016/03/04 10:39:23 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_treatnull(t_instr *instr, t_print *print)
{
	int		i;
	char	*null;
	int		length;

	length = 6;
	if (!(instr->flag & MIN) && instr->flag & PREC)
		ft_treatwidth(instr, print, 0);
	if (instr->flag & PREC)
		length = instr->precision;
	null = ft_strdup("(null)");
	i = -1;
	while (++i < length)
	{
		if (print->i % 32 == 0)
			print->res = ft_realloc(print->res, print->i, print->sz++ * 32);
		print->res[print->i++] = null[i];
	}
	if ((instr->flag & MIN) && instr->flag & PREC)
		ft_treatwidth(instr, print, 0);
	free(null);
}

static void		ft_printstr(t_instr *instr, t_print *print, va_list ap)
{
	char	*str;
	int		strlen;
	int		i;
	int		min;

	i = -1;
	str = va_arg(ap, char *);
	strlen = ft_strlen(str);
	if (str == NULL)
	{
		ft_treatnull(instr, print);
		return ;
	}
	if (instr->flag & PREC && strlen > instr->precision)
		min = instr->precision;
	else
		min = strlen;
	if (!(instr->flag & MIN))
		ft_treatwidth(instr, print, min);
	while (++i < min)
		ft_printinbuf(print, str[i]);
	if (instr->flag & MIN)
		ft_treatwidth(instr, print, min);
}

static void		ft_printwstr(wchar_t *str, int size, t_print *print)
{
	int		i;
	int		j;
	int		k;
	char	*s;

	i = -1;
	k = 0;
	while (str[++i] && k < size)
	{
		s = ft_getwchar(str[i]);
		j = -1;
		while (s[++j] != '\0')
		{
			k++;
			if (print->i % 32 == 0)
				print->res = ft_realloc(print->res, print->i, print->sz++ * 32);
			print->res[print->i++] = s[j];
		}
		free(s);
	}
}

static void		ft_treatwstr(t_instr *instr, t_print *print, va_list ap)
{
	wchar_t		*str;
	int			size;
	int			min;

	size = 0;
	str = va_arg(ap, wint_t *);
	if (str == NULL)
	{
		ft_treatnull(instr, print);
		return ;
	}
	if (instr->flag & PREC)
		size = ft_wcharlen(str, instr->precision);
	else
		size = ft_wcharlen(str, -1);
	if (instr->flag & PREC && size > instr->precision)
		min = instr->precision;
	else
		min = size;
	if (!(instr->flag & MIN))
		ft_treatwidth(instr, print, min);
	ft_printwstr(str, size, print);
	if (instr->flag & MIN)
		ft_treatwidth(instr, print, min);
}

void			ft_treatstr(t_instr *instr, t_print *print, va_list ap)
{
	if (instr->cs == 'S' || (instr->cs == 's' && instr->lm & L))
		ft_treatwstr(instr, print, ap);
	else
		ft_printstr(instr, print, ap);
}
