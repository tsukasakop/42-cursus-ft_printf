/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _stdio.ft.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 03:11:49 by tkondo            #+#    #+#             */
/*   Updated: 2024/07/28 06:33:12 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _STDIO_FT_H
# define _STDIO_FT_H
# include <stdbool.h>
# include <stdio.h>

int						ft_fputc(int c, FILE *stream);
size_t					ft_fwrite(const void *ptr, size_t size, size_t n_items,
							FILE *stream);
int						ft_printf(const char *format, ...);
int						ft_vfprintf(FILE *s, const char *format, va_list ap);

# define N_PRINTF_FLAGS 6

typedef enum e_prinf_flag
{
	PADDING_ZERO,
	ADJUST_RIGHT,
	PUT_BLANK,
	PUT_PLUS,
	ALTER_FORM,
	PRECITION
}						t_printf_flag;

typedef enum e_printf_prefix
{
	NONE,
	BLANK,
	PLUS,
	MINUS,
	LOWER_HEX,
	UPPER_HEX,
	LOWER_HEX_ONE
}						t_printf_prefix;

typedef enum e_printf_val_type
{
	NUM,
	CHAR,
	STR
}						t_printf_val_type;

typedef struct s_flag
{
	int					field;
	int					precition;
	bool				flag[N_PRINTF_FLAGS];
}						t_flag;

typedef struct s_fmt
{
	t_printf_val_type	val_type;
	t_printf_prefix		prefix;
	unsigned long long	val;
	unsigned char		pad_char;
	size_t				pad_len;
	int					pad_pos;
	bool				align_left;
	size_t				pref_len;
	size_t				val_len;
	unsigned int		base;
	int					(*table)(unsigned long long);
	va_list				*ap;
}						t_fmt;

#endif
