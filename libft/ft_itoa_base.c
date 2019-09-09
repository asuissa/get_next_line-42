/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 22:41:51 by asuissa           #+#    #+#             */
/*   Updated: 2017/12/25 00:18:29 by asuissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		error(char *base)
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

static int		nb_nb(int tmp)
{
	int	i;

	i = 0;
	if (tmp < 0)
	{
		tmp = -tmp;
		i++;
	}
	while (tmp > 10)
	{
		tmp = tmp / 10;
		i++;
	}
	return (i);
}

static void		ft_putnbrstr_base(int n, char *base, char **out)
{
	if (error(base))
		return ;
	if (n == -2147483648)
	{
		*out[0] = '-';
		*out[1] = base[2 % ft_strlen(base)];
		n = 147483648;
	}
	if (n < 0)
	{
		*out[0] = '-';
		n = -n;
	}
	if (n / ft_strlen(base))
	{
		ft_putnbrstr_base(n / ft_strlen(base), base, out);
		ft_putnbrstr_base(n % ft_strlen(base), base, out);
	}
	else
		*out = strncat(*out, &base[n], 1);
}

char			*ft_itoa_base(int nb, char *base)
{
	char	*out;

	if (error(base))
		return (NULL);
	if (!(out = ft_memalloc(nb_nb(nb))))
		return (NULL);
	ft_putnbrstr_base(nb, base, &out);
	return (out);
}
