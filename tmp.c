/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 22:57:17 by tkondo            #+#    #+#             */
/*   Updated: 2024/07/28 06:22:07 by tkondo           ###   ########.fr       */
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
	f=ft_printf;/*
	*/
	f("%10%");
	/*
	//f("[%d]\n", f("%-1s", "S"));
	f("[%d]\n", f(" %-2s", "S"));
	f("[%d]\n", f("%-3sy", "S"));
	f("[%d]\n", f(" % 1s", ""));
	f("[%d]\n", f("% 1s ", ""));
	printf(f("%c", '0');
	f(" %c ", '0');
	f(" %c", '0' - 256);
	f("%c ", '0' + 256);
	f(" %c", '0' - 256);
	f("%c ", '0' + 256);
	f("[%d]\n", f(" %d ", -1));
	f("[%d]\n", f(" %d ", 15));
	f("[%d]\n", f(" %d ", 16));
	f("[%d]\n", f(" %d ", 17));
	printf("[%d]\n", f("[ %.1s]\n", ""));
	f(" %.4d \n", 123456789);
	f(" % s \n", "123456789");
	f(" %.10d ", LONG_MAX);
	f("%15.10#0-+ s\n", NULL);
	f("%s", "");
	f(" %s", "");
	f("%s ", "");
	f(" %s ", "");
	f(" %s ", "-");
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
*/
	//ft_printf("%p\n", NULL);
	//printf("%p\n", NULL);
	(void)argc;
	(void)argv;
}
