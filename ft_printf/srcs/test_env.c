/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikaelberglund <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:26:05 by mikaelber         #+#    #+#             */
/*   Updated: 2020/02/12 22:43:23 by mikaelber        ###   ########.fr       */
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

void		run_test(t_testinfo *info, const char *legend, const char *format, ...)
{
	va_list ap;
	va_list	ap_copy;
	va_list	ap_copy2;
	int		len_diff[2];
	int		out_diff;
	char	*escaped;

	// run comparative tests with native vprintf
	va_start(ap, format);
	print_output_to_file(format, len_diff, ap);
	out_diff = compare_files(USR_FILE, EXP_FILE);

	if (info->opts & OFLAG_PRINT_OUTPUT)
	{
		va_copy(ap_copy, ap);
		va_copy(ap_copy2, ap);
	}

	// print output to file
	if (!(info->opts & OFLAG_PRINTALL))
		dprintf(1, "\r\033[K");
	escaped = ft_strescape(format);
	if (len_diff[0] != len_diff[1] || out_diff != 0)
	{
		if (info->passed != info->test_count && info->opts & OFLAG_PRINT)
			dprintf(1, "\033[1A");
		dprintf(1, "\033[0;31m[fail]\033[0m");
		dprintf(1, "\t%-15.15s\t%30.25s", escaped, legend);

		if (info->opts & (OFLAG_PRINTALL | OFLAG_PRINT))
		{
			if (info->opts & OFLAG_PRINT_OUTPUT)
			{
				dprintf(1, "\nout: [");
				ft_vdprintf(1, format, ap_copy);
				dprintf(1, "]\nexp: [");
				vdprintf(1, format, ap_copy2);
				dprintf(1, "]");
			}
			dprintf(1, "\n");
			if (info->opts & OFLAG_PRINT)
				dprintf(1, "\n");
		}
	}
	else
	{
		info->passed++;
		dprintf(1, "\033[0;32m[pass]\033[0m");
		dprintf(1, "\t%-15.15s\t%30.25s", escaped, legend);
		if (info->opts & OFLAG_PRINTALL)
		{
			if (info->opts & OFLAG_PRINT_OUTPUT)
			{
				dprintf(1, "\nout: [");
				ft_vdprintf(1, format, ap_copy);
				dprintf(1, "]\nexp: [");
				vdprintf(1, format, ap_copy2);
				dprintf(1, "]");
			}
			dprintf(1, "\n");
		}
	}
	info->test_count++;
	va_end(ap_copy);
	va_end(ap_copy2);
	va_end(ap);
	free(escaped);
}
