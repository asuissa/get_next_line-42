/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:48:51 by asuissa           #+#    #+#             */
/*   Updated: 2018/01/08 23:39:23 by asuissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

void	*ft_memalloc(size_t size)
{
	void	*out;

	if (size > INT_MAX)
		return (NULL);
	out = malloc(size);
	if (!out)
		return (NULL);
	ft_bzero(out, size);
	return (out);
}
