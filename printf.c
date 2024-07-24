/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 12:55:22 by tkondo            #+#    #+#             */
/*   Updated: 2024/07/19 22:56:39 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>

int	main(void)
{
	char c;
	char *s;
	void *p;
	int i;
	unsigned int ui;

	c = 'C';
	s = "STRING";
	p = 0x1234567890abcdef;
	i = -42;
	ui = 42;
	printf("c: %10c\n", c);
	printf("s: %10s\n", s);
	printf("p: %10p\n", p);
	printf("d: %10d\n", i);
	printf("i: %10i\n", i);
	printf("u: %10u\n", ui);
	printf("x: %10x\n", ui);
	printf("X: %10X\n", ui);
	printf("c: %c\n", c);
	printf("s: %s\n", s);
	printf("p: %p\n", p);
	printf("d: %d\n", i);
	printf("i: %i\n", i);
	printf("u: %u\n", ui);
	printf("x: %x\n", ui);
	printf("X: %X\n", ui);
	printf("d: %*d\n", 10, 10);
	printf("d: %.*d\n", 10, 10, 10);
	printf("d: %*.*1$d\n", 10, 10, 10);
	printf("d: %*.*d\n", 10, 15, 10);
	printf("d: %*.*1$d\n", 15, 10, 5);
	printf("d: %*.*3$d\n", 15, 10, 5);
	printf("d: %*.*d\n", 15, 10, 5);
	printf("d: %2$d, %1$d, %d\n", 1, 2, 3);

	printf("\"%%3$d %%3$d %%d\", 1, 2, 3\n", 1, 2, 3);
	printf("%3$d %3$d %d\n", 1, 2, 3);
	printf("\"%%2$d %%2$d %%d\", 1, 2, 3\n", 1, 2, 3);
	printf("%2$d %2$d %d\n", 1, 2, 3);
	printf("\"%%1$d %%1$d %%d\", 1, 2, 3\n", 1, 2, 3);
	printf("%1$d %1$d %d\n", 1, 2, 3);
	printf("\"%%0$d %%1$d %%d\", 1, 2, 3\n", 1, 2, 3);
	printf("%0$d %1$d %d\n", 1, 2, 3);
	printf("\"%%5$d %%4$d %%d\", 1, 2, 3\n", 1, 2, 3);
	printf("%5$d %4$d %d\n", 1, 2, 3);
	printf("\"%%2$d %%p %%3$p\", 1, 0xffffffffff, 3\n", 1, 2, 3);
	printf("%2$p %p %3p\n", 1, 0xffffffffff, 3);
	printf("%2$d %d %3$d\n", 1, 2, 3);//*/
} //*/
