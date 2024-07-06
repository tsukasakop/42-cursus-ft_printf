/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   literal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 01:23:00 by tkondo            #+#    #+#             */
/*   Updated: 2024/07/06 13:13:43 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.ft.h"
#include <stdbool.h>
#include <strings.h>

bool	test(char *s)
{
	int	std;
	int	ft;

	std = printf(s);
	ft = ft_printf(s);
	printf("\nstd:%d, ft:%d\n", std, ft);
	return (std == ft);
}

int	main(void)
{
	char	*cases[] = {													\
		"1234567890",														\
		"ABCDEFG", 															\
		"vwxyz",															\
		"",																	\
		"EOF"																\
	};
	int		cnt;

	cnt = 0;
	while (strcmp(cases[cnt], "EOF"))
	{
		if (cnt != 0)
			printf("--------------------------\n");
		printf("Case%d: %s\n", cnt, cases[cnt]);
		if (!test(cases[cnt]))
			return (1);
		cnt++;
	}
}
