/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 22:31:45 by asuissa           #+#    #+#             */
/*   Updated: 2018/01/08 22:37:31 by asuissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft/libft.h"
# define BUFF_SIZE 10000

typedef struct		s_init_gnl
{
	int				r;
	char			buffer[BUFF_SIZE + 1];
	char			*c;
	t_list			*tmp;
	size_t			b;
}					t_init_gnl;

int					get_next_line(const int fd, char **line);

#endif
