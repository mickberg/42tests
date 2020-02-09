/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_basics.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 16:40:56 by mikaelber         #+#    #+#             */
/*   Updated: 2020/02/09 20:12:01 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf_test.h"

void	test_basics(t_testinfo *info)
{
	run_test(info, "text no arg", "Hello world!");
	run_test(info, "empty format text no arg", "");
	run_test(info, "escaped chars", "\t\r\n\v\f\\");

	// %
	run_test(info, "precentage sign", "%");
	run_test(info, "precentage sign width", "5%");
	run_test(info, "precentage sign width 0flag", "05%");
	run_test(info, "precentage sign width 0flag lalgin", "-05%");
	run_test(info, "precentage sign width lalign", "-5%");

	// no specifiers
	run_test(info, "no spec", "%");
	run_test(info, "no spec width", "%5");
	run_test(info, "no spec width 0flag", "05%");
	run_test(info, "no spec width 0flag lalign", "-05%");
	run_test(info, "no spec width lalign", "-5%");
}
