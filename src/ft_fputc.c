/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fputc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:19:13 by tkondo            #+#    #+#             */
/*   Updated: 2024/07/24 17:28:21 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_stdio.ft.h"
#include <stdio.h>

int	ft_fputc(int c, FILE *stream)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	if (ft_fwrite(&uc, 1, 1, stream) == 0)
		return -1;
	return 1;
}
