/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 16:55:11 by mikaelber         #+#    #+#             */
/*   Updated: 2020/02/13 14:32:01 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf_test.h"

void	test_string(t_testinfo *info)
{
	char	*test_str;

	run_test(info, "s basic", "kalle %s", "anka");
	run_test(info, "s basic 2words", "%s", "kalle anka");
	run_test(info, "s basic 2strings", "%s%s", "frappo", "chino");
	run_test(info, "s basic 2strings 1empty", "..%s stuff %s", "kalle", "");

	// width
	run_test(info, "s width", "%10s", "kalle");
	run_test(info, "s width less", "%2s", "kalle");
	run_test(info, "s width more", "%10s", "kalle");
	run_test(info, "s width same", "%5s", "kalle");
	run_test(info, "s width sflag", "% 10s", "kalle");
	run_test(info, "s width 0flag", "%010s", "kalle");
	run_test(info, "s width 0flag lalign", "%-010s", "kalle");
	run_test(info, "s width 0flag lalign + precision", "%-010.3s", "kalle");

	// precision
	run_test(info, "s precision more", "%.10s", "kalle");
	run_test(info, "s precision same", "%.5s", "kalle");
	run_test(info, "s precision less", "%.2s", "kalle");

	test_str = ft_strnew(5);
	ft_memset(test_str, 0, sizeof(char) * 5);
	ft_strncpy(test_str, "kalle", 5);

	run_test(info, "s precision non-terminated str", "%s", test_str);
	run_test(info, "s precision non-terminated str", "%.5s", test_str);
	run_test(info, "s precision non-terminated str", "%.100s", test_str);

	free(test_str);
}
