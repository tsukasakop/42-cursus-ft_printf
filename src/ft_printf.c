/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 22:41:55 by tkondo            #+#    #+#             */
/*   Updated: 2024/07/25 11:45:22 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_stdio.ft.h"
#include <stdarg.h>
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		n;

	va_start(args, format);
	n = ft_vfprintf(stdout, format, args);
	va_end(args);
	return (n);
}
