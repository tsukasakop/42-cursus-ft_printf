/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _stdio.ft.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 03:11:49 by tkondo            #+#    #+#             */
/*   Updated: 2024/07/24 15:55:07 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _STDIO_FT_H
# define _STDIO_FT_H
# include <stdbool.h>
# include <stdio.h>

int					ft_fputc(int c, FILE *stream);
ssize_t				ft_fwrite(const void *ptr, size_t size, size_t n_items,
						FILE *stream);
int					ft_printf(const char *format, ...);
int					ft_vfprintf(FILE *s, const char *format, va_list ap);

# define N_PRINTF_FLAGS 6

typedef enum e_prinf_flag
{
	PADDING_ZERO, // for '-'
	ADJUST_RIGHT, // for '0'
	PUT_BLANK,    // for ' '
	PUT_PLUS,     // for '+'
	ALTER_FORM,   // for '#'
	UPPERCASE
}					t_printf_flag;

typedef enum e_printf_prefix
{
	NONE,
	BLANK,        // " " for ' ' flag
	PLUS,         // "+" for '+' flag
	MINUS,        //
	LOWER_HEX,    // "0x" for 'x' with '#' flag('X')
	UPPER_HEX,    // "0x" for 'x' with '#' flag('X')
	LOWER_HEX_ONE // "0x" for 'x' with '#' flag('X')
		UNKNOWN
}					t_printf_prefix;

typedef struct s_fmt
{
	int				field;
	int				precition;
	bool			flag[N_PRINTF_FLAGS];
	int				printlen;
	t_printf_prefix	prefix;
	unsigned int	base;
	int				(*table)(unsigned long long);
}					t_fmt;

#endif
