/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treatchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 16:35:38 by lgosse            #+#    #+#             */
/*   Updated: 2016/03/04 14:35:25 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_treatwidth(t_instr *instr, t_print *print, int minus)
{
	int		i;
	char	c;
	int		nb;

	i = 0;
	nb = instr->width - minus;
	if (instr->flag & ZERO && !(instr->flag & MIN))
		c = '0';
	else
		c = ' ';
	while (i < nb)
	{
		if (print->i % 32 == 0)
			print->res = ft_realloc(print->res, print->i, print->sz++ * 32);
		print->res[print->i++] = c;
		i++;
	}
}

static void	ft_printchar(t_instr *instr, t_print *print, va_list ap)
{
	if (!(instr->flag & MIN))
		ft_treatwidth(instr, print, 1);
	if (print->i % 32 == 0)
		print->res = ft_realloc(print->res, print->i, print->sz++ * 32);
	if (instr->cs == '%')
		print->res[print->i++] = '%';
	else
		print->res[print->i++] = (unsigned char)va_arg(ap, int);
	if (instr->flag & MIN)
		ft_treatwidth(instr, print, 1);
}

void		ft_treatchar(t_instr *instr, t_print *print, va_list ap)
{
	if (instr->cs == 'C' || (instr->cs == 'c' && instr->lm & L))
		ft_printwchar(instr, print, ft_getwchar(va_arg(ap, wint_t)));
	else
		ft_printchar(instr, print, ap);
}
