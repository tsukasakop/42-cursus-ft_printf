/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdio.ft.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 01:23:48 by tkondo            #+#    #+#             */
/*   Updated: 2024/09/05 17:08:23 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STDIO_FT_H
# define STDIO_FT_H

# include "types/t_FILE.h"
# include <stdarg.h>
# include <stddef.h>

int		ft_fputc(int c, t_FILE *stream);
size_t	ft_fwrite(const void *ptr, size_t size, size_t n_items, t_FILE *stream);
int		ft_printf(const char *format, ...);
int		ft_vfprintf(t_FILE *s, const char *format, va_list ap);
int		ft_fileno(t_FILE *s);

#endif
