/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treatsignednb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 10:15:43 by lgosse            #+#    #+#             */
/*   Updated: 2016/03/07 18:07:32 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			ft_printnb(t_print *print, char *nb)
{
	int		j;

	j = 0;
	if (nb[0] == '-')
		j++;
	while (nb[j] != '\0')
	{
		if (print->i % 32 == 0)
			print->res = ft_realloc(print->res, print->i, 32 * print->sz++);
		print->res[print->i++] = nb[j];
		j++;
	}
	free(nb);
}

void			ft_printinbuf(t_print *print, char c)
{
	if (print->i % 32 == 0)
		print->res = ft_realloc(print->res, print->i, 32 * print->sz++);
	print->res[print->i++] = c;
}

static int		ft_tsnb(t_instr *instr, t_print *print, int length, long nb)
{
	length = length > instr->precision ? length : instr->precision;
	if (nb == 0 && instr->flag & PREC && instr->precision == 0)
		length = 0;
	if ((instr->flag & PLUS && nb >= 0) || nb < 0)
		instr->width--;
	if (instr->flag & PREC)
		instr->flag &= NON_ZERO;
	if (!(instr->flag & PREC) && instr->flag & ZERO &&
		(nb < 0 || instr->flag & PLUS))
		nb >= 0 ? ft_printinbuf(print, '+') : ft_printinbuf(print, '-');
	return (length);
}

void			ft_treatsignednb(t_instr *instr, t_print *print, long nb)
{
	int		length;
	int		tmp;
	char	*n;

	length = ft_get_long_length(nb);
	tmp = instr->precision - length;
	length = ft_tsnb(instr, print, length, nb);
	if (instr->flag & SP && !(instr->flag & PLUS) && nb >= 0)
	{
		ft_printinbuf(print, ' ');
		instr->width--;
	}
	if (!(instr->flag & MIN) && instr->width > instr->precision)
		ft_treatwidth(instr, print, length);
	if ((instr->flag & PREC || !(instr->flag & ZERO)) &&
		(nb < 0 || instr->flag & PLUS))
		nb >= 0 ? ft_printinbuf(print, '+') : ft_printinbuf(print, '-');
	while (tmp-- > 0)
		ft_printinbuf(print, '0');
	n = ft_ltoa_base(nb, 10);
	if (!(nb == 0 && instr->flag & PREC && instr->precision == 0))
		ft_printnb(print, n);
	if (instr->flag & MIN)
		ft_treatwidth(instr, print, length);
}
