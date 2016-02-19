/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 19:11:50 by pbondoer          #+#    #+#             */
/*   Updated: 2016/02/19 18:28:48 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <unistd.h>

char	*get_append(t_gnl *gnl)
{
	int i;

	i = 0;
	while (gnl->i + i < gnl->count)
	{
		if (gnl->buf[gnl->i + i] == '\n')
		{
			i++;
			break;
		}
		i++;
	}
	gnl->i += i;
	return ft_strsub(gnl->buf, gnl->i - i, i - 1);
}

int get_next_line(int const fd, char **line)
{
	static t_gnl	*gnl;
	char			*temp;

	if (fd <= 0 || line == NULL)
		return (-1);
	if (gnl == NULL)
	{
		gnl = (t_gnl *)ft_memalloc(sizeof(t_gnl));
		gnl->buf = ft_strnew(BUFF_SIZE);
		gnl->count = 0;
		gnl->i = 0;
	}

	temp = ft_strnew(0);
	while (gnl->i <= gnl->count)
	{
		if(gnl->i == gnl->count)
		{
			gnl->count = read(fd, gnl->buf, BUFF_SIZE);
			gnl->i = 0;
			if (gnl->count == 0)
			{
				return (0);
			}
		}

		while (gnl->i < gnl->count)
		{
			temp = ft_strjoin(temp, get_append(gnl));

			if (gnl->i < gnl->count)
			{
				*line = temp;
				return (1);
			}
		}
	}
	return (0);
}
