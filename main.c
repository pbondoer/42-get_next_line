/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 15:07:35 by pbondoer          #+#    #+#             */
/*   Updated: 2016/02/19 15:21:37 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "get_next_line.h"

int		main(int argc, char **argv)
{
	char	*line;
	int		fd;

	if (argc != 2)
	{
		ft_putstr("usage: gnl input_file\n");
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) <= 0)
	{
		ft_putstr("error opening file ");
		ft_putstr(argv[1]);
		ft_putchar('\n');
		return (1);
	}
	ft_putstr("opened stream with fd ");
	ft_putnbr(fd);
	ft_putchar('\n');
	while (get_next_line(fd, &line))
	{
		ft_putstr(line);
		ft_putchar('\n');
	}
	ft_putstr("eof\n");

}
