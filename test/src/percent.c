/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 01:23:00 by tkondo            #+#    #+#             */
/*   Updated: 2024/07/06 13:54:40 by tkondo           ###   ########.fr       */
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
		"%%",																\
		"%%%%",												\
		"%%a%%w%%x%%y%%z%%",												\
		"EOF"																\
	};
	int		cnt;
	bool success = true;
	cnt = 0;
	while (strcmp(cases[cnt], "EOF"))
	{
		if (cnt != 0)
			printf("--------------------------\n");
		printf("Case%d: %s\n", cnt, cases[cnt]);
		success = (success && !test(cases[cnt]));
		cnt++;
	}
	return (!success);
}
