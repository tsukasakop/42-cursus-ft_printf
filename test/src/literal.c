/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   literal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 01:23:00 by tkondo            #+#    #+#             */
/*   Updated: 2024/07/06 03:21:50 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.ft.h"
#include <stdbool.h>

bool	test(char *s)
{
	int	std;
	int	ft;

	printf("--- test %s ------------------\n", s);
	std = printf(s);
	ft = ft_printf(s);
	printf("std:%d, ft:%d\n", std, ft);
	return (std == ft);
}

int	main(void)
{
	test("123456789\n");
	test("ABCDEFGhig\n");
	test("");
}
