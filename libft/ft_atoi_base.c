/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 21:43:25 by asuissa           #+#    #+#             */
/*   Updated: 2018/01/07 21:19:09 by asuissa          ###   ########.fr       */
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

int			ft_atoi_base(char *str, char *base)
{
	int	i;
	int	val;
	int	n;

	if (error(base))
		return (0);
	val = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	n = i;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_strchr(base, str[i]) && str[i])
	{
		val = val * ft_strlen(base) + (ft_strclen(base, str[i]));
		i++;
	}
	if (str[n] == '-')
		val = -val;
	return (val);
}
