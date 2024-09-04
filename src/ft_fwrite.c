/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fwrite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 01:02:25 by tkondo            #+#    #+#             */
/*   Updated: 2024/08/25 16:24:18 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "_stdio.ft.h"

size_t	ft_fwrite(const void *ptr, size_t size, size_t n_items, FILE *stream)
{
	size_t	cnt;
	ssize_t	writen;
	int	fn;

	fn = ft_fileno(stream);
	cnt = 0;
	while (cnt < n_items)
	{
		writen = write(fn, ptr + size * cnt, size);
		if (writen < 0 || (size_t)writen < size)
			break ;
		cnt++;
	}
	return (cnt);
}
