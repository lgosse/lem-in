/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treatunsignednb.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 13:25:09 by lgosse            #+#    #+#             */
/*   Updated: 2016/03/07 15:52:19 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_printunsignedattributes(t_instr *instr, t_print *print, char *nb)
{
	if (((instr->flag & HT && (instr->cs == 'o' ||
		instr->cs == 'O' || instr->cs == 'b' || instr->cs == 'B' ||
		instr->cs == 'x' || instr->cs == 'X')) && nb[0] != '0') ||
		instr->cs == 'p')
	{
		if (print->i % 32 == 0)
			print->res = ft_realloc(print->res, print->i, print->sz++ * 32);
		print->res[print->i++] = '0';
		if (print->i % 32 == 0)
			print->res = ft_realloc(print->res, print->i, print->sz++ * 32);
		if (instr->cs != 'o' && instr->cs != 'O' && instr->cs != 'p')
			print->res[print->i++] = instr->cs;
		if (instr->cs == 'p')
			print->res[print->i++] = 'x';
	}
}

static char	*ft_choose_ultoa(t_instr *instr, long nb)
{
	char	*n;

	n = NULL;
	if (instr->lm & J && !ft_strchr("xXoObB", instr->cs))
		n = ft_ultoa_base(nb, 10);
	else if (instr->cs == 'u')
		n = ft_ultoa_base(nb, 10);
	else if (instr->cs == 'p')
		n = ft_ltoa_base(nb, 16);
	else if (instr->cs == 'x' || instr->cs == 'X')
		n = ft_ltoa_base(nb, 16);
	else if (instr->cs == 'U' || (instr->cs == 'u' && (instr->lm & L ||
					instr->lm & LL)))
		n = ft_ultoa_base(nb, 10);
	else if (instr->cs == 'O' || (instr->cs == 'o' && (instr->lm & L ||
					instr->lm & LL)))
		n = ft_ultoa_base(nb, 8);
	else if (instr->cs == 'o')
		n = ft_ltoa_base(nb, 8);
	else if (instr->cs == 'b' || instr->cs == 'B')
		n = ft_ltoa_base(nb, 2);
	if (instr->cs >= 'A' && instr->cs <= 'Z')
		ft_strupcase(n);
	return (n);
}

static int	ft_get_right_length(t_instr *instr, t_print *print, char *nb)
{
	int		length;

	length = ft_strlen(nb);
	if (length < instr->precision)
		length = instr->precision;
	if ((instr->flag & HT && nb[0] != '0') || instr->cs == 'p')
	{
		if (instr->cs == 'o')
			length += 1;
		else
			length += 2;
	}
	if ((!(instr->flag & PREC) && instr->flag & ZERO && (instr->cs == 'x' ||
				instr->cs == 'X' || instr->cs == 'p')))
		ft_printunsignedattributes(instr, print, nb);
	if (instr->flag & ZERO && instr->flag & PREC)
		instr->flag = instr->flag & NON_ZERO;
	if ((nb[0] == '0' && instr->flag & PREC))
		length--;
	if (!(instr->flag & MIN))
		ft_treatwidth(instr, print, length);
	return (length);
}

void		ft_treatunsignednb(t_instr *instr, t_print *print, unsigned long nb)
{
	int		tmp;
	char	*n;
	int		length;

	n = ft_choose_ultoa(instr, nb);
	length = ft_get_right_length(instr, print, n);
	tmp = ft_strlen(n);
	if (instr->flag & PREC || !(instr->flag & ZERO))
		ft_printunsignedattributes(instr, print, n);
	if (n[0] == '0' && ft_strchr("xXp", instr->cs))
		tmp--;
	if (instr->precision > tmp)
		while (tmp++ < instr->precision)
		{
			if (print->i % 32 == 0)
				print->res = ft_realloc(print->res, print->i, print->sz++ * 32);
			print->res[print->i++] = '0';
		}
	if (!(nb == 0 && instr->flag & PREC) || (instr->flag & HT &&
		!ft_strchr("xXp", instr->cs)))
		ft_printnb(print, n);
	if (instr->flag & MIN)
		ft_treatwidth(instr, print, length);
}
