/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 22:41:55 by tkondo            #+#    #+#             */
/*   Updated: 2024/07/20 02:59:55 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_stdio.ft.h"
#include "libft.h"
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdarg.h>

int	print_percent(FILE *s, char **f, va_list ap)
{
	++*f;
	(void)ap;
	return (ft_fwrite("%", 1, 1, s));
}

int print_c(FILE *s, char **f, va_list ap)
{
	++*f;
	char c = va_arg(ap, int) & 0b1111111;
	return (ft_fwrite(&c, 1, 1, s));
}

int print_s(FILE *s, char **f, va_list ap)
{
	++*f;
	char *str = va_arg(ap, char*);
	return (ft_fwrite(str, ft_strlen(str), 1, s));
}

int	print_fmt(FILE *s, char **f, va_list ap)
{
	if (**f == '%')
		return (print_percent(s, f, ap));
	if (**f == 'c')
		return (print_c(s, f, ap));
	if (**f == 's')
		return (print_s(s, f, ap));
	return (0);
}

int	ft_vfprintf(FILE *s, const char *format, va_list ap)
{
	int		cnt;
	ssize_t	_cnt;
	char	*tmp;

	cnt = 0;
	tmp = (char *)format;
	while (*tmp != '\0')
	{
		if (*tmp != '%')
			_cnt = ft_fwrite(tmp++, 1, 1, s);
		else
		{
			++tmp;
			_cnt = print_fmt(s, &tmp, ap);
		}
		if (_cnt == -1 || cnt >= INT_MAX - _cnt)
			return (-1);
		cnt += _cnt;
	}
	(void)ap;
	return (cnt);
}
