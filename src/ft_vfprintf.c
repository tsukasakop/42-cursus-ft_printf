/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 22:41:55 by tkondo            #+#    #+#             */
/*   Updated: 2024/07/25 10:46:17 by tkondo           ###   ########.fr       */
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
	fmt->prefix = NONE;
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

int	p(FILE *s, t_fmt *fmt, unsigned long long v, size_t size)
{
	int	cnt;
	int	tmp;

	cnt = 0;
	if (v / fmt->base)
	{
		tmp = p(s, fmt, v / fmt->base, size - 1);
		if (tmp == -1 || (size_t)tmp != size - 1) 
			return (tmp);
		cnt += tmp;
	}
	if (fmt->printlen)
	{
		tmp = ft_fputc(fmt->table(v), s);
		if (tmp != 1)
			return (tmp);
		cnt += tmp;
		fmt->printlen--;
	}
	return (cnt);
}

unsigned long long	get_val(va_list ap, t_fmt *fmt, char conv)
{
	int	v;

	if (conv == '%')
		return 0;
	if (conv == 'c')
		return (unsigned long long)(unsigned char)va_arg(ap, unsigned int);
	else if (conv == 'u' || conv == 'x' || conv == 'X')
		return (unsigned long long)va_arg(ap, unsigned int);
	else if (conv == 'p')
	{
		fmt->prefix = LOWER_HEX;
		return (unsigned long long)va_arg(ap, void *);
	}
	else if (conv == 'd' || conv == 'i')
	{
		v = va_arg(ap, int);
		if (v < 0)
		{
			fmt->prefix = MINUS;
			v *= -1;
		}
		return (unsigned long long)(unsigned int)v;
	}
	return 0;
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

size_t get_psize(t_printf_prefix prefix)
{
	size_t size;size=0;
	
	if (prefix == BLANK)
		size++;
	if (prefix == PLUS)
		size++;
	if (prefix == MINUS)
		size++;
	if (prefix == LOWER_HEX)
		size+=2;
	if (prefix == UPPER_HEX)
		size+=2;
	if (prefix == LOWER_HEX_ONE)
		size+=3;
	return size;
}
size_t get_vsize(unsigned long long v, t_fmt *fmt)
{
	size_t size;size=1;
	while(v / fmt->base)
	{
		size++;
		v /= fmt->base;
	}
	return size;
}

int ps(FILE *s, char *str, t_fmt *fmt)
{
	(void)fmt;
	if (str == NULL)str = "(null)";
	size_t size;size = ft_strlen(str);
	size_t ret;ret = ft_fwrite(str, size, 1, s);
	if(ret == 0)
		return -1;
	return size; 
}

int	print_fmt(FILE *s, char **f, va_list ap)
{
	t_fmt				fmt;
	unsigned long long	v;

	reset_fmt(&fmt);
	// set_fmt(f, ap, &fmt);
	if (**f == 's')
	{++*f;
		return ps(s, va_arg(ap,char*), &fmt);
	}
	if (!ft_strchr("cdiupxX%", **f))
		return (0);
	v = get_val(ap, &fmt, **f);
	set_base(**f, &fmt);
	size_t psize;psize = get_psize(fmt.prefix);
	size_t vsize;vsize = get_vsize(v, &fmt);
	if (psize > INT_MAX - 1 - vsize)
		return -1;
	++*f;
	int tmp  = fprint_prefix(s, fmt.prefix);
	if(tmp == -1)
		return -1;
	int size;size = tmp;
	tmp = p(s, &fmt, v, vsize);
	if(tmp == -1)
		return -1;
	return size + tmp;
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
			_cnt = ft_fputc(*tmp++, s);
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
