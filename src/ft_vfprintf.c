/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 22:41:55 by tkondo            #+#    #+#             */
/*   Updated: 2024/07/24 12:53:54 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_stdio.ft.h"
#include "libft.h"
#include <limits.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>

static void	reset_fmt(t_fmt *fmt)
{
	fmt->printlen = INT_MAX - 1;
}

int	percent_table(unsigned long long val)
{
	(void)val;
	return ('%');
}

int	dec_table(unsigned long long val)
{
	return ((val % 10) + '0');
}

int	lower_hex_table(unsigned long long val)
{
	return ("0123456789abcdef"[val % 16]);
}

int	upper_hex_table(unsigned long long val)
{
	return ("0123456789ABCDEF"[val % 16]);
}

int	base256table(unsigned long long val)
{
	return (val % 256);
}

int	fprint_prefix(FILE *s, int pref)
{
	if (pref == BLANK)
		return (ft_fwrite(" ", 1, 1, s));
	if (pref == PLUS)
		return (ft_fwrite("+", 1, 1, s));
	if (pref == MINUS)
		return (ft_fwrite("-", 1, 1, s));
	if (pref == LOWER_HEX)
		return (ft_fwrite("0x", 2, 1, s));
	if (pref == UPPER_HEX)
		return (ft_fwrite("0X", 2, 1, s));
	if (pref == LOWER_HEX_ONE)
		return (ft_fwrite("0x1", 3, 1, s));
	return (0);
}

int	p(FILE *s, t_fmt *fmt, unsigned long long v)
{
	int	cnt;
	int	tmp;

	cnt = 0;
	if (v / fmt->base)
	{
		tmp = p(s, fmt, v / fmt->base);
		if (tmp == -1)
			return (-1);
		cnt += tmp;
	}
	if (fmt->printlen)
	{
		tmp = ft_fputc(fmt->table(v), s);
		if (tmp == -1)
			return (-1);
		cnt += tmp;
		fmt->printlen--;
	}
	return (cnt);
}

int	pa(FILE *s, t_fmt *fmt, unsigned long long *v)
{
	int	cnt;
	int	tmp;

	cnt = fprint_prefix(s, fmt->prefix);
	if (cnt == -1)
		return (-1);
	tmp = p(s, fmt, *v);
	if (tmp == -1)
		return (-1);
	return (cnt + tmp);
}

bool	get_val(unsigned long long **val, va_list ap, t_fmt *fmt, char conv)
{
	int	v;

	if (conv == '%')
		**val = 0;
	else if (conv == 'c')
		**val = (unsigned long long)(unsigned char)va_arg(ap, unsigned int);
	else if (conv == 'u' || conv == 'x' || conv == 'X')
		**val = (unsigned long long)va_arg(ap, unsigned int);
	else if (conv == 'p')
	{
		fmt->prefix = LOWER_HEX;
		**val = (unsigned long long)va_arg(ap, void *);
	}
	else if (conv == 'd' || conv == 'i')
	{
		v = va_arg(ap, int);
		if (v < 0)
		{
			fmt->prefix = MINUS;
			v *= -1;
		}
		**val = (unsigned long long)(unsigned int)v;
	}
	else
		return (false);
	return (true);
}

void	set_base(unsigned char conv, t_fmt *fmt)
{
	if (conv == '%')
	{
		fmt->base = 1;
		fmt->table = percent_table;
	}
	if (conv == 'c')
	{
		fmt->base = 256;
		fmt->table = base256table;
	}
	if (conv == 'd' || conv == 'i' || conv == 'u')
	{
		fmt->base = 10;
		fmt->table = dec_table;
	}
	if (conv == 'x' || conv == 'p')
	{
		fmt->base = 16;
		fmt->table = lower_hex_table;
	}
	if (conv == 'X')
	{
		fmt->base = 16;
		fmt->table = upper_hex_table;
	}
}

int	print_fmt(FILE *s, char **f, va_list ap)
{
	t_fmt				fmt;
	unsigned long long	v;
	unsigned long long	*val;

	reset_fmt(&fmt);
	// set_fmt(f, ap, &fmt);
	if (!ft_strchr("csdiupxX%", **f))
		return (0);
	val = &v;
	get_val(&val, ap, &fmt, **f);
	set_base(**f, &fmt);
	++*f;
	return (pa(s, &fmt, val));
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
