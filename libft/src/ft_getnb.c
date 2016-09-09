/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 15:45:22 by lgosse            #+#    #+#             */
/*   Updated: 2016/03/04 14:28:23 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_get_unsignednb(t_instr *instr, t_print *print, va_list ap)
{
	unsigned long	nb;

	if (instr->lm & HH && instr->cs == 'O')
		nb = va_arg(ap, int);
	else if (instr->lm & HH && instr->cs != 'U')
		nb = (unsigned char)va_arg(ap, int);
	else if (instr->lm & H && instr->cs != 'U')
		nb = (unsigned short)va_arg(ap, int);
	else if (instr->lm & L || instr->cs == 'O' || instr->cs == 'U' ||
			instr->cs == 'B' || instr->lm & LL)
		nb = va_arg(ap, unsigned long);
	else if (instr->lm & J)
		nb = (unsigned long)va_arg(ap, unsigned long);
	else if (instr->lm & Z)
		nb = (size_t)va_arg(ap, ssize_t);
	else
		nb = (unsigned int)va_arg(ap, unsigned int);
	ft_treatunsignednb(instr, print, nb);
}

static void		ft_get_signednb(t_instr *instr, t_print *print, va_list ap)
{
	long		nb;
	int			nbr;

	nbr = 0;
	if (instr->lm & HH && instr->cs != 'D')
		nb = (char)va_arg(ap, int);
	else if (instr->lm & H && instr->cs != 'D')
		nb = (short)va_arg(ap, int);
	else if (instr->lm & H && instr->cs == 'D')
		nb = (unsigned int)va_arg(ap, unsigned int);
	else if (instr->lm & LL)
		nb = va_arg(ap, long);
	else if (instr->lm & L || instr->cs == 'D')
		nb = va_arg(ap, long);
	else if (instr->lm & J)
		nb = va_arg(ap, intmax_t);
	else if (instr->lm & Z)
		nb = va_arg(ap, ssize_t);
	else
	{
		nbr = va_arg(ap, int);
		nb = nbr;
	}
	ft_treatsignednb(instr, print, nb);
}

void			ft_redirectnb(t_instr *instr, t_print *print, va_list ap)
{
	if (instr->cs == 'p')
	{
		instr->flag |= HT;
		ft_treatunsignednb(instr, print, va_arg(ap, long) & -1);
	}
	else if (ft_strchr("oOuUxXbB", instr->cs))
		ft_get_unsignednb(instr, print, ap);
	else
		ft_get_signednb(instr, print, ap);
}
