/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 22:57:17 by tkondo            #+#    #+#             */
/*   Updated: 2024/07/23 06:35:26 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//usr/bin/cc -L. -lftprintf $0 -o /tmp/a.out && /tmp/a.out; exit

#include "include/stdio.ft.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

int main(int argc, char** argv)
{
	int (*f)(const char *,...);
	f=printf;
	f(" %c", '0' - 256);
	f("%c ", '0' + 256);
/*
	f("%d\n", INT_MAX);
	f("%d\n", INT_MIN);
	f("%d\n", LONG_MAX);
	f("%d\n", LONG_MIN);
	f("%d\n", ULONG_MAX);
	f("%d\n", 0);
	f("%d\n", -42);
*/
	//ft_printf("%d\n", 0);
	//ft_printf("%d\n", 42);
	//ft_printf("%d\n", -42);
	//ft_printf("%c\n", 'a');
	//ft_printf("%p", 'x');
	//printf("%p", 'x');
	(void)argc;
	(void)argv;
}
