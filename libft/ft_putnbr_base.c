/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 19:07:31 by asuissa           #+#    #+#             */
/*   Updated: 2017/12/24 23:59:00 by asuissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	error(char *base)
{
	int	i;

	if (!*base || !base || (ft_strlen(base) < 2))
		return (1);
	i = 0;
	while (base[i])
	{
		if (ft_strnchr(base, base[i]) > 1)
			return (1);
		if (base[i] == '+' || base[i] == '-')
			return (1);
		i++;
	}
	return (0);
}

void		ft_putnbr_base(int n, char *base)
{
	if (error(base))
		return ;
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar(base[2 % ft_strlen(base)]);
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n / ft_strlen(base))
	{
		ft_putnbr_base(n / ft_strlen(base), base);
		ft_putnbr_base(n % ft_strlen(base), base);
	}
	else
		ft_putchar(base[n]);
}
