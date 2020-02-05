/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:43:12 by mikaelber         #+#    #+#             */
/*   Updated: 2020/02/05 22:46:49 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_test.h"

int		main(int argc, char **argv)
{
	FILE *res_fd;

	(void)argv;
	res_fd = fopen(OUT_FILE, "w");
	// testers
	test_int(res_fd);
	// print output & cleanup
	fclose(res_fd);
	print_file(OUT_FILE);
	remove(USR_FILE);
	remove(EXP_FILE);
	printf("Test ended.\n");
	if (argc > 1)
		while (1);
	return (0);
}
