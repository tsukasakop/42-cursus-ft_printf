/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _stdio.ft.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 03:11:49 by tkondo            #+#    #+#             */
/*   Updated: 2024/07/06 03:11:55 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _STDIO_FT_H
# define _STDIO_FT_H
# include <stdio.h>

size_t	ft_fwrite(const void *ptr, size_t size, size_t n_items, FILE *stream);
int		ft_printf(const char *format, ...);
int		ft_vfprintf(FILE *s, const char *format, va_list ap);

#endif
