/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:46:08 by mikaelber         #+#    #+#             */
/*   Updated: 2020/02/05 23:32:56 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_test.h"

void	test_int(FILE *res_fd)
{
	// test width
	run_test(res_fd, "d basic", "%d", 12);
	run_test(res_fd, "i basic", "%i", 12);
	run_test(res_fd, "d basic no arg", "%d");
	run_test(res_fd, "d basic negative", "%d", -12);
	run_test(res_fd, "d basic zero", "%d", 0);
	run_test(res_fd, "d basic pos", " int last %d", 123);
	run_test(res_fd, "d pos first ", "%d int last", 123);
	run_test(res_fd, "d multiple", "%d int%d all around %d", 2, 5, 1);
	run_test(res_fd, "d multiple neg", "%d int%d all around %d", -2, -5, -1);
	run_test(res_fd, "d width", "%10d", 123);
	run_test(res_fd, "d width left align ", "%-10d", 123);
	run_test(res_fd, "d width, 0", "%10d", 0);
	run_test(res_fd, "d width, 0, 0 flag", "%010d", 0);
	run_test(res_fd, "d width, 0, 0 flag with precicion", "%010.0d", 1);
	run_test(res_fd, "d width, 0, sign", "%+10.0d", 0);
	run_test(res_fd, "d width, 0, sign left align", "%+-10d", 0);
	run_test(res_fd, "d width, 0, space flag, left align", "% -10d", 0);
	run_test(res_fd, "d width exact fit", "%3d", 123);
	run_test(res_fd, "d width exact fit, left align", "%-3d", 123);
	run_test(res_fd, "d width exact fit, left align, sign", "%-+3d", 123);
	run_test(res_fd, "d width exact fit, left align, space", "% -3d", 123);
	run_test(res_fd, "d width exact fit, precision overflow", "%3.4d", 123);
	run_test(res_fd, "d width exact fit, precision overflow left align", "%-3.4d", 123);
	run_test(res_fd, "d width exact fit, precision overflow, sign", "%+3.4d", 123);
	run_test(res_fd, "d width exact fit, precision overflow, neg", "%3.4d", -123);
}
