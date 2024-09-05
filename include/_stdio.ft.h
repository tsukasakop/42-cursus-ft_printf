/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _stdio.ft.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 03:11:49 by tkondo            #+#    #+#             */
/*   Updated: 2024/09/05 17:02:40 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _STDIO_FT_H
# define _STDIO_FT_H
# include "libft.h"
# include "stdio.ft.h"
# include <stdbool.h>
# include <stdlib.h>
# include <limits.h>

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
	bool				flag[6];
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
	va_list				ap;
}						t_fmt;

#endif
