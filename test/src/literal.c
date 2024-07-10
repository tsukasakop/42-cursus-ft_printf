/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   literal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 01:23:00 by tkondo            #+#    #+#             */
/*   Updated: 2024/07/10 20:18:04 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			if(*s == '\0')
				return;
		}
		s++;
	}
}

bool	test(char *s)
{
	int	std;
	int	ft;

	ft_printf("\x1B[31m");
	std = printf(s);
	ft_printf("\x1B[32m");
	ft = ft_printf(s);
	printf("\x1B[0m");
	printf("\nstd:%d, ft:%d\n", std, ft);
	return (std == ft);
}


int	main(void)
{
	char	*cases[] = {													\
		"1234567890",														\
		"ABCDEFG", 															\
		"vwxyz",															\
		"\n\t\f\r\v",														\
		"",																	\
		"EOF"																\
	};
	int		cnt;

	cnt = 0;
	while (strcmp(cases[cnt], "EOF"))
	{
		if (cnt != 0)
			printf("--------------------------\n");
		printf("Case%d: ", cnt);
		fflush(stdout);
		putstr_caret(cases[cnt]);
		printf("\n");
		if (!test(cases[cnt]))
			return (1);
		cnt++;
	}
}
