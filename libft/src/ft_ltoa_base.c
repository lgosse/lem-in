/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:34:57 by lgosse            #+#    #+#             */
/*   Updated: 2016/03/03 17:39:10 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

static char		*ft_lother(long n, int base)
{
	int				i;
	char			*nb;
	char			*tab;
	unsigned long	nbr;

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

long			ft_abslong(long nb)
{
	if (nb < 0 & nb >= -9223372036854775807)
		return (-nb);
	return (nb);
}

static char		*ft_ldecimal(long n)
{
	long	tmp;
	int		i;
	char	*nb;

	i = 1;
	tmp = n;
	while ((tmp /= 10))
		i++;
	if (n < 0)
	{
		tmp = 1;
		i++;
	}
	if (!(nb = ft_strnew(i)))
		return (NULL);
	nb[i] = '\0';
	while (i--)
	{
		nb[i] = ft_abslong(n % 10) + '0';
		n /= 10;
	}
	if (tmp == 1)
		nb[0] = '-';
	return (nb);
}

char			*ft_ltoa_base(long n, int base)
{
	if (base == 10)
		return (ft_ldecimal(n));
	else
		return (ft_lother(n, base));
}
