/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 22:41:55 by tkondo            #+#    #+#             */
/*   Updated: 2024/07/19 21:51:39 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_stdio.ft.h"
#include <limits.h>

int	ft_vfprintf(FILE *s, const char *format, va_list ap)
{
	int		cnt;
	ssize_t	_cnt;
	char	*tmp;

	cnt = 0;
	tmp = (char *)format;
	while (*tmp != '\0')
	{
		_cnt = ft_fwrite(tmp, 1, 1, s);
		if(_cnt == -1 || cnt >= INT_MAX - _cnt)
			return -1;
		tmp++;
		cnt+=_cnt;
	}
	(void)ap;
	return (cnt);
}
