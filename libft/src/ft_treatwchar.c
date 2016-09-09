/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treatwchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 17:20:15 by lgosse            #+#    #+#             */
/*   Updated: 2016/03/28 17:18:45 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_convert_wint(wint_t wc, int n, int bone, int bzero)
{
	long	mask;
	long	mask_nb;
	int		len;
	int		nb;

	len = -1;
	mask = 1;
	mask_nb = 1;
	nb = 0;
	while (++len < n)
	{
		if (mask & bone)
			nb = nb | bone;
		else if (mask & bzero)
			;
		else
		{
			if (wc & mask_nb)
				nb = nb | mask;
			mask_nb = mask_nb << 1;
		}
		mask = mask << 1;
	}
	return (nb);
}

char		*ft_getwchar(wint_t nb)
{
	char	*s;
	int		len;
	int		i;

	if (nb == 0)
		return (ft_strdup(""));
	i = -1;
	len = ft_get_nb_length(nb, 2);
	if (len < 8 && (len = 1))
		;
	else if (len < 12 && (len = 2))
		nb = ft_convert_wint(nb, 16, B12, B02);
	else if (len < 17 && (len = 3))
		nb = ft_convert_wint(nb, 24, B13, B03);
	else if (len < 22 && (len = 4))
		nb = ft_convert_wint(nb, 32, B14, B04);
	s = (char *)malloc(sizeof(char) * (len + 1));
	while (len--)
		s[++i] = ((nb >> (8 * len)) & ~((unsigned)(-1) << 8));
	s[++i] = '\0';
	return (s);
}

int			ft_wcharlen(wchar_t *s, int n)
{
	int		i;
	int		len;
	int		len_w;

	i = -1;
	len = 0;
	while (s[++i])
	{
		len_w = ft_get_nb_length(s[i], 2);
		if (len_w < 8)
			len_w = 1;
		else if (len_w < 12)
			len_w = 2;
		else if (len_w < 17)
			len_w = 3;
		else if (len_w < 22)
			len_w = 4;
		if (n == -1 || (len + len_w <= n))
			len += len_w;
		else
			break ;
	}
	return (len);
}

void		ft_printwchar(t_instr *instr, t_print *print, char *s)
{
	int		i;
	int		first;

	i = -1;
	first = 0;
	if (!(instr->flag & MIN))
		ft_treatwidth(instr, print, 1);
	while (s[++i] != '\0' || first == 0)
	{
		first = 1;
		if (print->i % 32 == 0)
			print->res = ft_realloc(print->res, print->i, print->sz++ * 32);
		print->res[print->i++] = s[i];
	}
	free(s);
	if (instr->flag & MIN)
		ft_treatwidth(instr, print, 1);
}
