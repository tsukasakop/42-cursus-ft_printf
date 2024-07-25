/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fwrite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 01:02:25 by tkondo            #+#    #+#             */
/*   Updated: 2024/07/25 11:46:15 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

size_t	ft_fwrite(const void *ptr, size_t size, size_t n_items, FILE *stream)
{
	size_t	cnt;
	ssize_t	writen;

	cnt = 0;
	while (cnt < n_items)
	{
		writen = write(stream->_file, ptr + cnt, size);
		if (writen < 0 || (size_t)writen < size)
			break ;
		cnt++;
	}
	return (cnt);
}
