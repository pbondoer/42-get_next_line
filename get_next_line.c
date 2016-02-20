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

int get_next_line(int const fd, char **line)
{
	static t_gnl	*gnl;
	char			*temp;

	if (fd < 0 || line == NULL)
		return (-1);
	if (gnl == NULL)
	{
		gnl = (t_gnl *)ft_memalloc(sizeof(t_gnl));
		gnl->buf = ft_strnew(BUFF_SIZE);
		gnl->count = BUFF_SIZE;
		gnl->i = BUFF_SIZE;
	}

	temp = ft_strnew(0);
	while (gnl->count > 0)
	{
		if(gnl->i == gnl->count)
		{
			// ft_putstr("read new buffer\n");
			gnl->count = read(fd, gnl->buf, BUFF_SIZE);
			if (gnl->count == -1)
				return (-1);
			gnl->i = 0;
			if (gnl->count == 0)
			{
				// ft_putstr("count 0, eof\n");
				if (gnl->nl == 0)
				{
					// ft_putstr("expected eof, joining and returning\n");
					*line = ft_strjoin(temp, get_append(gnl));
					return (1);
				}
			}
		}

		// ft_putstr("[buffer]\n");
		// ft_putstr(&(gnl->buf[gnl->i]));
		// ft_putstr("\n[buffer]\n");
		while (gnl->i < gnl->count)
		{
			temp = ft_strjoin(temp, get_append(gnl));
			// ft_putstr("i = ");
			// ft_putnbr(gnl->i);
			// ft_putstr("; c = ");
			// ft_putnbr(gnl->count);
			// ft_putstr("\n");
			if (gnl->nl)
			{
				// ft_putstr("returning\n");
				*line = temp;
				return (1);
			}
		}
	}

	return (0);
}
