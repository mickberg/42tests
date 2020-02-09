/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_basics.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 16:40:56 by mikaelber         #+#    #+#             */
/*   Updated: 2020/02/07 16:54:39 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf_test.h"

void	test_basics(FILE *res_fp)
{
	run_test(res_fp, "text no arg", "Hello world!");
	run_test(res_fp, "empty format text no arg", "");
	run_test(res_fp, "escaped chars", "\t\r\n\v\f\\");

	// %
	run_test(res_fp, "precentage sign", "%");
	run_test(res_fp, "precentage sign width", "5%");
	run_test(res_fp, "precentage sign width 0flag", "05%");
	run_test(res_fp, "precentage sign width 0flag lalgin", "-05%");
	run_test(res_fp, "precentage sign width lalign", "-5%");

	// no specifiers
	run_test(res_fp, "no spec", "%");
	run_test(res_fp, "no spec width", "%5");
	run_test(res_fp, "no spec width 0flag", "05%");
	run_test(res_fp, "no spec width 0flag lalign", "-05%");
	run_test(res_fp, "no spec width lalign", "-5%");
}
