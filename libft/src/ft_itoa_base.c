/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:34:57 by lgosse            #+#    #+#             */
/*   Updated: 2016/03/03 17:38:52 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

static char		*ft_iother(int n, int base)
{
	int				i;
	char			*nb;
	char			*tab;
	unsigned int	nbr;

	i = 1;
	tab = ft_strdup("0123456789abcdef");
	nbr = n & -1;
	while ((nbr /= base))
		i++;
	nbr = n & -1;
	if (!(nb = ft_strnew(i)))
		return (NULL);
	nb[i] = '\0';
	while (i--)
	{
		nb[i] = tab[nbr % base];
		nbr /= base;
	}
	free(tab);
	return (nb);
}

static char		*ft_idecimal(int n)
{
	int		tmp;
	int		i;
	char	*nb;

	i = 1;
	tmp = n;
	while ((tmp /= 10))
		i++;
	if (n < 0)
	{
		n = -n;
		tmp = 1;
		i++;
	}
	if (!(nb = ft_strnew(i)))
		return (NULL);
	nb[i] = '\0';
	while (i--)
	{
		nb[i] = (n % 10) + '0';
		n /= 10;
	}
	if (tmp == 1)
		nb[0] = '-';
	return (nb);
}

char			*ft_itoa_base(int n, int base)
{
	if (base == 10)
		return (ft_idecimal(n));
	else
		return (ft_iother(n, base));
}
