/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_test.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:46:58 by mikaelber         #+#    #+#             */
/*   Updated: 2020/02/09 19:40:44 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_TEST_H
# define FT_PRINTF_TEST_H

# include "libft.h"
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

typedef struct s_testinfo	t_testinfo;

/*
** Test funcs
*/

void				run_test(t_testinfo *info, const char *legend, const char *format, ...);
void				test_int(t_testinfo *info);
void				test_basics(t_testinfo *info);
void				test_string(t_testinfo *info);

/*
** Utils
*/
int					compare_files(const char *f1, const char *f2);
void				print_to_file(const char *dst, const char *str);
void				merge_files(const char *dst, const char *src);
void				print_file(const char *src);

struct				s_testinfo
{
	int		passed;
	int		test_count;
};

#endif
