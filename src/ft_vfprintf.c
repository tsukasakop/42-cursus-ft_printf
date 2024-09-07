/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 22:41:55 by tkondo            #+#    #+#             */
/*   Updated: 2024/09/08 02:03:57 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_stdio.ft.h"

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

int	fprint_prefix(t_FILE *s, t_printf_prefix pref, size_t size)
{
	size_t	ret;

	if (pref == BLANK)
		ret = (ft_fwrite(" ", 1, size, s));
	else if (pref == PLUS)
		ret = (ft_fwrite("+", 1, size, s));
	else if (pref == MINUS)
		ret = (ft_fwrite("-", 1, size, s));
	else if (pref == LOWER_HEX)
		ret = (ft_fwrite("0x", 1, size, s));
	else if (pref == UPPER_HEX)
		ret = (ft_fwrite("0X", 1, size, s));
	else if (pref == LOWER_HEX_ONE)
		ret = (ft_fwrite("0x1", 1, size, s));
	else
		ret = 0;
	if (ret == size)
		return (ret);
	else
		return (-1);
}

int	p(t_FILE *s, t_fmt *fmt, unsigned long long v, size_t size)
{
	int	chi_cnt;
	int	cur_cnt;

	if (size == 0)
		return 0;
	chi_cnt = p(s, fmt, v / fmt->base, size - 1);
	if (chi_cnt == -1 || chi_cnt >= INT_MAX - 1)
		return -1;
	if ((size_t)chi_cnt != size - 1)
		return (chi_cnt);
	cur_cnt = ft_fputc(fmt->table(v), s);
	if (cur_cnt == -1)
		return (-1);
	if (cur_cnt == 0)
		return (chi_cnt);
	return (chi_cnt + cur_cnt);
}

void	set_val(t_fmt *fmt, char c, va_list ap)
{
	int	v;

	if (c == '%')
		fmt->val = '%';
	else if (c == 'c')
		fmt->val = (unsigned long long)(unsigned char)va_arg(ap, unsigned int);
	else if (c == 's')
		fmt->val = (unsigned long long)(va_arg(ap, char *));
	else if (ft_strchr("uxX", c))
		fmt->val = (unsigned long long)va_arg(ap, unsigned int);
	else if (c == 'p')
	{
		fmt->prefix = LOWER_HEX;
		fmt->val = (unsigned long long)va_arg(ap, void *);
	}
	else if (ft_strchr("id", c))
	{
		v = va_arg(ap, int);
		if (v < 0)
		{
			fmt->pref_len = 1;
			fmt->prefix = MINUS;
			v *= -1;
		}
		fmt->val = ((unsigned long long)(unsigned int)v);
	}
}

void	set_base(t_fmt *fmt, char c)
{
	if (ft_strchr("diu", c) != NULL)
	{
		fmt->base = 10;
		fmt->table = dec_table;
	}
	else if (ft_strchr("xp", c) != NULL)
	{
		fmt->base = 16;
		fmt->table = lower_hex_table;
	}
	else if (c == 'X')
	{
		fmt->base = 16;
		fmt->table = upper_hex_table;
	}
}

size_t	get_psize(t_printf_prefix prefix)
{
	size_t	size;

	size = 0;
	if (prefix == BLANK)
		size++;
	if (prefix == PLUS)
		size++;
	if (prefix == MINUS)
		size++;
	if (prefix == LOWER_HEX)
		size += 2;
	if (prefix == UPPER_HEX)
		size += 2;
	if (prefix == LOWER_HEX_ONE)
		size += 3;
	return (size);
}

void	set_vsize(t_fmt *fmt, t_flag *flag)
{
	unsigned long long v;

	v = fmt->val;
	if (fmt->val_type == STR)
	{
		if(v == 0)
			fmt->val_len = ft_strlen("(null)");
		else
			fmt->val_len = ft_strlen((const char *)v);
		if(flag->flag[PRECITION] && (int)fmt->val_len > flag->precition)
			fmt->val_len = flag->precition;
	}
	else if (fmt->val_type == CHAR)
		fmt->val_len = 1;
	else
	{
		fmt->val_len = 1;
		while (v / fmt->base)
		{
			fmt->val_len++;
			v /= fmt->base;
		}
		if(flag->flag[PRECITION] && ((int)fmt->val_len < flag->precition))
			fmt->val_len = flag->precition;
	}
}

int	ps(t_FILE *s, char *str, t_fmt *fmt, size_t size)
{
	size_t	ret;

	(void)fmt;
	if (str == NULL)
		str = "(null)";
	ret = ft_fwrite(str, size, 1, s);
	if (ret == 0)
		return (-1);
	return (size);
}

int	get_digit(char **f)
{
	int	d;

	d = 0;
	while (**f >= '0' && **f <= '9')
		d = d * 10 + *(*f)++ - '0';
	return (d);
}

void	set_flag(char **f, t_flag *flag)
{
	char c;
	while (1)
	{
		c = *(*f)++;
		if (c == '.')
		{
			flag->flag[PRECITION] = true;
			flag->precition = get_digit(f);
		}
		else if (c == ' ')
			flag->flag[PUT_BLANK] = true;
		else if (c == '+')
			flag->flag[PUT_PLUS] = true;
		else if (c == '-')
			flag->flag[ADJUST_RIGHT] = true;
		else if (c == '#')
			flag->flag[ALTER_FORM] = true;
		else if (c == '0')
			flag->flag[PADDING_ZERO] = true;
		else
		{
			--*f;
			if (c >= '1' && c <= '9')
				flag->field = get_digit(f);
			else
				return ;
		}
	}
}

void set_pref(char c, t_flag *flag, t_fmt *fmt)
{
	if(ft_strchr("di", c) != NULL)
	{
		if(fmt->prefix == MINUS)
			;
		else if (flag->flag[PUT_PLUS])
			fmt->prefix = PLUS;
		else if (flag->flag[PUT_BLANK])
			fmt->prefix = BLANK;
		else
			return;
		fmt->pref_len = 1;
	}
	else if(ft_strchr("xX", c) && flag->flag[ALTER_FORM])
	{
		if(c == 'x')
			fmt->prefix = LOWER_HEX;
		if(c == 'X')
			fmt->prefix = UPPER_HEX;
		fmt->pref_len = 2;
	}
	else if(c == 'p')
	{
		fmt->prefix = LOWER_HEX;
		fmt->pref_len = 2;
	}
}

void	trim_flag(t_flag *flag, t_fmt *fmt)
{
	if (flag->flag[PUT_PLUS])
		flag->flag[PUT_BLANK] = false;
	if (flag->flag[ADJUST_RIGHT])
		flag->flag[PADDING_ZERO] = false;
	if (flag->precition > 0 && fmt->val_type == NUM)
		flag->flag[PADDING_ZERO] = false;
}

void set_pad(t_fmt *fmt, t_flag *flag)
{
	if((size_t)flag->field <= fmt->val_len || flag->field - fmt->val_len <= fmt->pref_len)
		;
	else if(flag->flag[PADDING_ZERO])
		fmt->val_len = flag->field - fmt->pref_len;
	else
	{
		fmt->pad_len = flag->field - fmt->pref_len - fmt->val_len;
		fmt->align_left = flag->flag[ADJUST_RIGHT];
	}
}

bool calc_fmt(t_fmt *fmt, char **f, va_list ap)
{
	t_flag	flag;
	char c;
	ft_bzero(&flag, sizeof(t_flag));
	set_flag(f, &flag);
	if (**f == '\0' || ft_strchr("csdiupxX%", **f) == NULL)
		return false;
	c = *(*f)++;
	ft_bzero(fmt, sizeof(t_fmt));
	fmt->prefix = NONE;
	if(ft_strchr("c%", c) != NULL)
		fmt->val_type = CHAR;
	else if(c =='s')
		fmt->val_type = STR;
	else
		fmt->val_type = NUM;
	trim_flag(&flag, fmt);
	set_pref(c, &flag, fmt);
	set_val(fmt, c, ap);
	if (ft_strchr("xX", c) && fmt->val == 0)
	{
		fmt->prefix = NONE;
		fmt->pref_len = 0;
	}
	if (fmt->val_type == NUM)
		set_base(fmt, c);
	set_vsize(fmt, &flag);
	set_pad(fmt, &flag);
	return true;
}

#include <stdio.h>
int	print_fmt(t_FILE *s, char **f, va_list ap)
{
	t_fmt	*fmt;
	int		cnt;
	int		tmp;
	int		size;

	cnt = 0;
	fmt = ft_calloc(1, sizeof(t_fmt));
	if(fmt==NULL)
		return -1;
	if(!calc_fmt(fmt, f, ap))
	{
		free(fmt);
		if (**f != '\0')
			cnt = ft_fputc('%', s);
		return cnt*2-1;
	}
	while (!fmt->align_left && cnt < (int)fmt->pad_len)
	{
		cnt++;
		ft_fputc(' ',s);
	}
	size = fprint_prefix(s, fmt->prefix, fmt->pref_len);
	if (size == -1)
		return (-1);
	if (fmt->val_type == STR)
		tmp = ps(s, (char *)fmt->val, fmt, fmt->val_len);
	else if(fmt->val_type == CHAR)
		tmp = ft_fputc(fmt->val, s);
	else
		tmp = p(s, fmt, fmt->val, fmt->val_len);
	if (tmp == -1)
		return (-1);
	while (fmt->align_left && cnt < (int)fmt->pad_len)
	{
		cnt++;
		ft_fputc(' ',s);
	}
	free(fmt);
	return (cnt + size + tmp);
}

int	ft_vfprintf(t_FILE *s, const char *format, va_list ap)
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
