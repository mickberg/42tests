/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_test.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:46:58 by mikaelber         #+#    #+#             */
/*   Updated: 2020/02/05 23:16:26 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_TEST_H
# define FT_PRINTF_TEST_H

# include "ft_printf.h"
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <float.h>
# include <string.h>

# define OUT_FILE "test_results.txt"
# define USR_FILE "usr_out.txt"
# define EXP_FILE "exp_out.txt"

/*
** Test funcs
*/

void	run_test(FILE *res_fd, const char *legend, const char *format, ...);
void	test_int(FILE *res_fd);

/*
** Utils
*/
int		compare_files(const char *f1, const char *f2);
void	print_to_file(const char *dst, const char *str);
void	merge_files(const char *dst, const char *src);
void	print_file(const char *src);

#endif
