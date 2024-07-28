/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 22:57:17 by tkondo            #+#    #+#             */
/*   Updated: 2024/07/28 22:14:01 by tkondo           ###   ########.fr       */
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
	f=printf;/*
	*/
f("[%d]\n",f("%5c, %5c, %5c", '5', 'x', 'n'));
f("[%d]\n",f("%10c, %10c, %10c", '5', 'x', 'n'));
f("[%d]\n",f("%100c, %100c, %100c", '5', 'x', 'n'));
f("[%d]\n",f("%10s, %10s, %10s, %10s", (char *)NULL, "", "test", "joihwhhgsdkhksdgsdgtvnrfa25252b6"));
f("[%d]\n",f("%100s, %100s, %100s, %100s", (char *)NULL, "", "test", "joihwhhgsdkhksdgsdgtvnrfa25252b6"));
f("[%d]\n",f("%5p, %5p, %5p, %5p, %5p, %5p", (void *)0, (void *)0xABCDE, (void *)ULONG_MAX, (void *)LONG_MIN, (void *)-1, (void *)-2352));
f("[%d]\n",f("%10p, %10p, %10p, %10p, %10p, %10p", (void *)0, (void *)0xABCDE, (void *)ULONG_MAX, (void *)LONG_MIN, (void *)-1, (void *)-2352));
f("[%d]\n",f("%100p, %100p, %100p, %100p, %100p, %100p", (void *)0, (void *)0xABCDE, (void *)ULONG_MAX, (void *)LONG_MIN, (void *)-1, (void *)-2352));
f("[%d]\n",f("%5d, %5d, %5d, %5d, %5d, %5d, %5d, %5d", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX));
f("[%d]\n",f("%10d, %10d, %10d, %10d, %10d, %10d, %10d, %10d", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX));
f("[%d]\n",f("%100d, %100d, %100d, %100d, %100d, %100d, %100d, %100d", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX));
f("[%d]\n",f("%5i, %5i, %5i, %5i, %5i, %5i, %5i, %5i", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX));
f("[%d]\n",f("%10i, %10i, %10i, %10i, %10i, %10i, %10i, %10i", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX));
f("[%d]\n",f("%100i, %100i, %100i, %100i, %100i, %100i, %100i, %100i", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX));
f("[%d]\n",f("%5u, %5u, %5u, %5u, %5u, %5u, %5u, %5u, %5u, %5u", 0, 5, -1, -10, 100, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX));
f("[%d]\n",f("%10u, %10u, %10u, %10u, %10u, %10u, %10u, %10u, %10u, %10u", 0, 5, -1, -10, 100, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX));
f("[%d]\n",f("%100u, %100u, %100u, %100u, %100u, %100u, %100u, %100u, %100u, %100u", 0, 5, -1, -10, 100, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX));
f("[%d]\n",f("%5x, %5x, %5x, %5x, %5x, %5x, %5x, %5x, %5x, %5x", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX));
f("[%d]\n",f("%10x, %10x, %10x, %10x, %10x, %10x, %10x, %10x, %10x, %10x", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX));
f("[%d]\n",f("%100x, %100x, %100x, %100x, %100x, %100x, %100x, %100x, %100x, %100x", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX));
f("[%d]\n",f("%5X, %5X, %5X, %5X, %5X, %5X, %5X, %5X, %5X, %5X", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX));
f("[%d]\n",f("%10X, %10X, %10X, %10X, %10X, %10X, %10X, %10X, %10X, %10X", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX));
f("[%d]\n",f("%100X, %100X, %100X, %100X, %100X, %100X, %100X, %100X, %100X, %100X", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX));
	/*

	f("[%d]\n", f(" %#x ", 0));
	f("[%d]\n", f(" %#x ", LONG_MIN));
	f("[%d]\n", f(" %#x %#x %#x %#x %#x %#x %#x", INT_MAX, INT_MIN, LONG_MAX,LONG_MIN, ULONG_MAX, 0, -42));
	f("[%d]\n", f(" %#X ", 0));
	f("[%d]\n", f(" %#X ", LONG_MIN));
	f("[%d]\n", f(" %#X %#X %#X %#X %#X %#X %#X", INT_MAX, INT_MIN, LONG_MAX,LONG_MIN, ULONG_MAX, 0, -42));
	f("%10%");

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
