/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 01:23:00 by tkondo            #+#    #+#             */
/*   Updated: 2024/07/23 01:22:01 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "stdio.ft.h"
#include <stdbool.h>
#include <strings.h>
#include <unistd.h>

void	putstr_caret(char *s)
{
	char c [2] = "^@";
	while(1)
	{
		if(*s >= ' ' && *s <= '~')
			write(1, s, 1);
		else {
			c[1] = ('@' + *s) & 127;
			write(1, "\x1B[30;47m", 8);
			write(1, c, 2);
			write(1, "\x1B[0m", 4);
		}
		if(*s == '\0')
			break;
		s++;
	}
}

void	test(char *str)
{
	int	std;
	int	ft;
	char *s = evaluate_escape_sequences(str);
	printf("Case: ");
	fflush(stdout);
	putstr_caret(s);
	printf("\x1B[31m\n");
	std = printf(s);
	printf("\x1B[32m\n");
	ft = ft_printf(s);
	printf("\x1B[0m\n");
	char *result = std == ft ? "\x1B[32mSUCCESS\x1B[0m" : "\x1B[31mFAILUE\x1B[0m";
	printf("result: %s\n(ret) \x1B[31mstd\x1B[0m:%d, \x1B[32mft\x1B[0m:%d\n", result, std, ft);
	free(s);
}
