/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fwrite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 01:02:25 by tkondo            #+#    #+#             */
/*   Updated: 2024/07/19 21:41:49 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

ssize_t	ft_fwrite(const void *ptr, size_t size, size_t n_items, FILE *stream)
{
	return write(stream->_file, ptr, size*n_items);
}
