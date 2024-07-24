/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 22:57:17 by tkondo            #+#    #+#             */
/*   Updated: 2024/07/25 01:22:34 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//usr/bin/cc -g -L. -lftprintf $0 -o /tmp/a.out && /tmp/a.out; exit

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
	f("%d\n", INT_MAX);
	f("%d\n", INT_MIN);
	f("%d\n", LONG_MAX);
	f("%d\n", LONG_MIN);
	f("%d\n", ULONG_MAX);
	f("%d\n", 0);
	f("%d\n", 42);
	f("%d\n", -42);
	f("%c\n", '0');
	f("%s\n", "123456789%d", 12);
	//ft_printf("%p\n", NULL);
	//printf("%p\n", NULL);
	(void)argc;
	(void)argv;
}
