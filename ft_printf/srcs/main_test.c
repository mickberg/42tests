/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:43:12 by mikaelber         #+#    #+#             */
/*   Updated: 2020/02/13 14:46:00 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_test.h"

int			main(int argc, char **argv)
{
	t_testinfo	info;

	ft_bzero(&info, sizeof(t_testinfo));
	if (!get_arguments(argc, argv, &info))
		return (0);
	// testers
	test_basics(&info);
	test_int(&info);
	test_string(&info);

	dprintf(1, "\r\033[K[%d of %d] tests passed\n", info.passed, info.test_count);

	// cleanup
	remove(USR_FILE);
	remove(EXP_FILE);

	if (info.opts & OFLAG_LEAKS)
		system("leaks ft_printf_test.o");
	return (0);
}
