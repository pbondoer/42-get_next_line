/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 19:11:50 by pbondoer          #+#    #+#             */
/*   Updated: 2016/02/19 16:12:39 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <unistd.h>

int get_next_line(int const fd, char **line)
{
	static char	*buf;
	static int	count;
	int			i;
	char		*temp;
	char		*append;

	if (fd <= 0 || line == NULL)
		return (-1);
	if (buf == NULL)
	{
		ft_putstr("allocating buff\n");
		buf = (char *)ft_memalloc(sizeof(char) * BUFF_SIZE);
		temp = ft_strnew(0);
	}
	i = 0;
	count = 0;
	while (i == count)
	{
		count = read(fd, buf, BUFF_SIZE);
		if (count == 0)
		{
			ft_putstr("reached eof\n");
			return (0);
		}
		ft_putstr("\033[32m");
		ft_putstr(buf);
		ft_putchar('\n');
		ft_putstr("\033[0m");
		append = NULL;
		i = 0;
		while (i < count)
		{
			if (buf[i] == '\n')
			{
				ft_putstr("\t\tappend set\n");
				append = ft_strsub(buf, 0, i);
				i++;
				break;
			}
			i++;
		}
		if (append == NULL)
			append = buf;
		temp = ft_strjoin(temp, append);

		if (i == count)
		{
			ft_putstr("\tno newline found, looping again\n");
		}
		else
		{
			ft_putstr("\tfound newline at pos ");
			ft_putnbr(i);
			ft_putchar('\n');
		}
	}

	ft_putstr("got out of loop\n");

	*line = temp;
	return (1);
}
