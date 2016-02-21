/* ************************************************************************** */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 19:11:50 by pbondoer          #+#    #+#             */
/*   Updated: 2016/02/19 18:40:15 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>

char	*get_append(t_gnl *gnl)
{
	int i;

	i = 0;
	gnl->nl = 0;
	while (gnl->i + i < gnl->count)
	{
		if (gnl->buf[gnl->i + i] == '\n')
		{
			gnl->nl = 1;
			i++;
			break;
		}
		i++;
	}
	gnl->i += i;
	return ft_strsub(gnl->buf, gnl->i - i, i - gnl->nl);
}

t_gnl	*get_gnl(t_list **lst, int fd)
{
	t_gnl	*gnl;
	t_list	*temp;

	temp = *lst;
	while (temp)
	{
		gnl = (t_gnl *)(temp->content);
		if (gnl->fd == fd)
			return (gnl);
		temp = temp->next;
	}
	gnl = (t_gnl *)ft_memalloc(sizeof(t_gnl));
	gnl->buf = ft_strnew(BUFF_SIZE);
	gnl->count = BUFF_SIZE;
	gnl->i = BUFF_SIZE;
	gnl->fd = fd;
	gnl->nl = 1;
	temp = ft_lstnew(gnl, sizeof(t_gnl));
	ft_lstadd(lst, temp);
	return ((t_gnl *)(temp->content));
}

void	del_one_gnl(void *ptr, size_t size)
{
	t_gnl	*gnl;

	(void)size;
	gnl = (t_gnl *)ptr;
	ft_memdel((void **)&(gnl->buf));
	ft_memdel(&ptr);
}

void	del_gnl(t_list **lst, int fd)
{
	t_gnl *gnl;
	t_list **temp;

	temp = lst;
	while (*temp)
	{
		gnl = (t_gnl *)((*temp)->content);
		if (gnl->fd == fd)
			break;
		*temp = ((*temp)->next);
	}
	if (*temp)
		ft_lstdel(temp, &del_one_gnl);
}

int get_next_line(int const fd, char **line)
{
	static t_list	*lst;
	t_gnl			*gnl;
	char			*temp;

	if (fd < 0 || line == NULL)
		return (-1);
	gnl = get_gnl(&lst, fd);
	temp = ft_strnew(0);
	while (gnl->count > 0)
	{
		if(gnl->i == gnl->count)
		{
			gnl->count = read(fd, gnl->buf, BUFF_SIZE);
			if (gnl->count == -1)
			{
				del_gnl(&lst, fd);
				return (-1);
			}
			gnl->i = 0;
			if (gnl->count == 0)
			{
				if (gnl->nl == 0)
				{
					*line = temp;
					return (1);
				}
			}
		}
		while (gnl->i < gnl->count)
		{
			temp = ft_strjoin(temp, get_append(gnl));
			if (gnl->nl)
			{
				*line = temp;
				return (1);
			}
		}
	}
	del_gnl(&lst, fd);
	return (0);
}
