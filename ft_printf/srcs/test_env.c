/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:26:05 by mikaelber         #+#    #+#             */
/*   Updated: 2020/02/07 21:01:21 by mikaelber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_test.h"

static void print_output_to_file(const char *format, int out_diff[2], va_list ap)
{
	FILE	*fd;
	int		stdout_cpy;
	va_list	ap_usr;
	va_list ap_exp;

	va_copy(ap_usr, ap);
	va_copy(ap_exp, ap);
	// print test output
	stdout_cpy = dup(fileno(stdout));
	fd = fopen(USR_FILE, "w");
	dup2(fileno(fd), fileno(stdout));
	out_diff[0] = ft_vprintf(format, ap_usr);
	fflush(stdout);
	fclose(fd);
	// print expected output
	fd = fopen(EXP_FILE, "w");
	dup2(fileno(fd), fileno(stdout));
	out_diff[1] = vprintf(format, ap_exp);
	fflush(stdout);
	fclose(fd);
	// reset file descriptor
	dup2(stdout_cpy, fileno(stdout));
	va_end(ap_usr);
	va_end(ap_exp);
}

void		run_test(FILE *res_fd, const char *legend, const char *format, ...)
{
	va_list ap;
	int		len_diff[2];
	int		out_diff;
	char	*escaped;

	// run comparative tests with native vprintf
	va_start(ap, format);
	print_output_to_file(format, len_diff, ap);
	out_diff = compare_files(USR_FILE, EXP_FILE);
	va_end(ap);

	// print output to file
	if (len_diff[0] != len_diff[1] || out_diff != 0)
		fprintf(res_fd, "\033[0;31m[fail]\033[0m");
	else
		fprintf(res_fd, "\033[0;32m[pass]\033[0m");
	escaped = ft_strescape(format);
	fprintf(res_fd, "\t%-30s\t%s\n", escaped, legend);
	free(escaped);
}
