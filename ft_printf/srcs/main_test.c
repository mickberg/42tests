/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:43:12 by mikaelber         #+#    #+#             */
/*   Updated: 2020/02/09 19:56:01 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_test.h"

int		main(int argc, char **argv)
{
	t_testinfo	info;
	(void)argv;

	ft_bzero(&info, sizeof(t_testinfo));
	// testers
	test_basics(&info);
	test_int(&info);
	test_string(&info);

	dprintf(1, "\r\033[K[%d of %d] tests passed\n", info.passed, info.test_count);

	// cleanup
	remove(USR_FILE);
	remove(EXP_FILE);
	if (argc > 1)
		while (1);
	return (0);
}
