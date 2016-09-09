/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 15:43:11 by lgosse            #+#    #+#             */
/*   Updated: 2016/03/03 16:28:23 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_print	*ft_init_print(void)
{
	t_print	*print;

	print = (t_print *)malloc(sizeof(t_print));
	if (print)
	{
		print->i = 0;
		print->sz = 1;
		print->res = (char *)malloc(sizeof(char) * (print->sz++) * 32);
		if (print->res)
			return (print);
	}
	return (NULL);
}

t_instr	*ft_init_instr(t_instr *instr)
{
	if (instr)
		free(instr);
	if ((instr = (t_instr *)malloc(sizeof(t_instr))))
	{
		instr->flag = 0;
		instr->width = 0;
		instr->precision = 0;
		instr->lm = 0;
		instr->cs = 0;
		instr->attributes = 0;
		return (instr);
	}
	return (NULL);
}
