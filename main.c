/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 15:07:35 by pbondoer          #+#    #+#             */
/*   Updated: 2016/02/20 05:35:10 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	char	*line;
	int		fd;
	/*
	int		out;
	int		p[2];

	out = dup(1);
	pipe(p);
	fd = 1;
	dup2(p[1], fd);	
	write(fd, "abcdefgh\n", 9);
	write(fd, "ijklmnop\n", 9);
	write(fd, "qrstuvwx\n", 9);
	write(fd, "yzabcdef\n", 9);
	write(fd, "ghijklmn\n", 9);
	write(fd, "opqrstuv\n", 9);
	write(fd, "wxyzabcd\n", 9);
	close(p[1]);
	dup2(out, fd);

	get_next_line(p[0], &line);
	printf("line: '%s', cmp: %d\n", line, strcmp(line, "abcdefgh"));
	get_next_line(p[0], &line);
	printf("line: '%s', cmp: %d\n", line, strcmp(line, "ijklmnop"));
	get_next_line(p[0], &line);
	printf("line: '%s', cmp: %d\n", line, strcmp(line, "qrstuvwx"));
	get_next_line(p[0], &line);
	printf("line: '%s', cmp: %d\n", line, strcmp(line, "yzabcdef"));
	get_next_line(p[0], &line);
	printf("line: '%s', cmp: %d\n", line, strcmp(line, "ghijklmn"));
	get_next_line(p[0], &line);
	printf("line: '%s', cmp: %d\n", line, strcmp(line, "opqrstuv"));
	get_next_line(p[0], &line);
	printf("line: '%s', cmp: %d\n", line, strcmp(line, "wxyzabcd"));
	*/
	fd = 42;
	ft_putnbr(get_next_line(fd, &line));
	/*
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
		ft_putstr("\033[33m'");
		ft_putstr(line);
		// ft_putnbr(ft_strcmp(line, "abcdefgh"));
		ft_putstr("'\033[0m");
		ft_putchar('\n');
	}
	*/
}
