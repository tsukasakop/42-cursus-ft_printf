/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_by_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 22:19:21 by tkondo            #+#    #+#             */
/*   Updated: 2024/07/10 21:11:19 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	exec(int fd, void (*f)(char *))
{
	char	*row;

	row = get_next_line(fd);
	if (row == NULL)
		return ;
	f(row);
	free(row);
	return (exec(fd, f));
}

static void	iter_files(int fcount, char **fnames, void (*f)(char *), int i)
{
	int		fd;

	if (i >= fcount)
		return ;
	fd = open(fnames[i], O_RDONLY);
	exec(fd, f);
	close(fd);
	return (iter_files(fcount, fnames, f, ++i));
}

void	exec_by_line(int fcount, char **fnames, void (*f)(char *))
{
	if (fcount < 1)
	{
		exec(STDIN_FILENO, f);
		return ;
	}
	iter_files(fcount, fnames, f, 0);
}
