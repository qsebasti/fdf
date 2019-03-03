/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:37:32 by qsebasti          #+#    #+#             */
/*   Updated: 2018/01/10 18:46:34 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	dizaine(int nb)
{
	int				count;
	unsigned int	n;

	count = 0;
	n = nb;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		n = -nb;
		count++;
	}
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char		*ft_itoa(int n)
{
	char			*s;
	unsigned int	nb;
	int				neg;
	int				i;

	if (n == 0)
		return (ft_strdup("0"));
	neg = (n > 0 ? 0 : 1);
	nb = (n > 0 ? n : -n);
	if (!(s = (char *)malloc(sizeof(char) * (dizaine(n) + 1))))
		return (NULL);
	s[dizaine(n)] = '\0';
	i = dizaine(n) - 1;
	while (nb > 0)
	{
		s[i] = nb % 10 + '0';
		nb = nb / 10;
		i--;
	}
	neg ? s[0] = '-' : neg;
	return (s);
}
