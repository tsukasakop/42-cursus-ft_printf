/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 22:41:55 by tkondo            #+#    #+#             */
/*   Updated: 2024/09/05 16:46:57 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_stdio.ft.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		n;

	t_FILE	_stdout;
	_stdout._fileno=1;
	va_start(args, format);
	n = ft_vfprintf(&_stdout, format, args);
	va_end(args);
	return (n);
}
