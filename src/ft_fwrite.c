/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fwrite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 01:02:25 by tkondo            #+#    #+#             */
/*   Updated: 2024/07/06 03:13:25 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_stdio.ft.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

// works only stream is stdout
size_t	ft_fwrite(const void *ptr, size_t size, size_t n_items, FILE *stream)
{
	size_t	towrite;

	towrite = size * n_items;
	write(stream->_file, ptr, towrite);
	return (towrite);
}
